/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** AnimatedTexture.cpp
*/

#include "AnimatedTexture.hpp"

AnimatedTexture::AnimatedTexture(irr::IrrlichtDevice *idevice, irr::video::ITexture *itexture, irr::s32 divX, irr::s32 divY)
{
    Device = idevice;

    texture = itexture;

    irr::core::dimension2d<irr::s32> spriteSize(texture->getSize());
    spriteSize.Width = spriteSize.Width / divX;
    spriteSize.Height = spriteSize.Height / divY;

    frame.set_used(divX * divY);

    irr::u32 n = 0;
    for(irr::s32 j=0; j<divY; j++)
        for(irr::s32 i=0; i<divX; i++) {
            frame[n] = irr::core::rect<irr::s32>(
                    i*spriteSize.Width, j*spriteSize.Height,
                    (i+1)*spriteSize.Width, (j+1)*spriteSize.Height);
            n++;
        }

    currentFrame = 0;

    position.UpperLeftCorner = irr::core::position2d<irr::s32>(0,0);
    position.LowerRightCorner = irr::core::position2d<irr::s32>(spriteSize.Width,spriteSize.Height);

    currentAnim = 0;
}

AnimatedTexture::AnimatedTexture(AnimatedTexture &other)
{
    texture = other.texture;

    frame.set_used(other.frame.size());
    for(irr::u32 i=0; i<frame.size(); i++) frame[i] = other.frame[i];

    currentFrame = 0;

    position.UpperLeftCorner = irr::core::position2d<irr::s32>(0,0);
    position.LowerRightCorner = other.position.LowerRightCorner - other.position.UpperLeftCorner;

    animation.set_used(other.animation.size());
    for(irr::u32 i=0; i<animation.size(); i++) {
        animation[i].start = other.animation[i].start;
        animation[i].end = other.animation[i].end;
        animation[i].speed = other.animation[i].speed;
        animation[i].loop = other.animation[i].loop;
        animation[i].reverse = other.animation[i].reverse;
    }

    currentAnim = 0;

    Device = other.Device;
}

void AnimatedTexture::draw(irr::u32 num)
{
    irr::core::rect<irr::s32> newPosition = irr::core::rect<irr::s32>(
            position.UpperLeftCorner.X,
            position.UpperLeftCorner.Y,
            position.LowerRightCorner.X * _scaleX,
            position.LowerRightCorner.Y * _scaleY);
    Device->getVideoDriver()->draw2DImage(texture, newPosition, frame[num], 0, 0, true);
}

void AnimatedTexture::setScale(irr::f32 scaleX, irr::f32 scaleY)
{
    _scaleX = scaleX;
    _scaleY = scaleY;
}

void AnimatedTexture::play()
{
    if(animation.empty()) {
        draw(0);
        return;
    }

    irr::u32 time = Device->getTimer()->getTime();

    if(oldTime + animation[currentAnim].speed <= time) {
        if(animation[currentAnim].reverse) {
            currentFrame--;
            if(currentFrame < animation[currentAnim].start) {
                if(animation[currentAnim].loop)
                    currentFrame = animation[currentAnim].end;
                else
                    currentFrame++;
            }
        } else {
            currentFrame++;

            if(currentFrame > animation[currentAnim].end) {
                if (animation[currentAnim].loop)
                    currentFrame = animation[currentAnim].start;
                else
                    currentFrame--;
            }
        }

        oldTime = time;
    }

    draw(currentFrame);
}

irr::u32 AnimatedTexture::addAnimation(irr::u32 start, irr::u32 end, irr::u32 speed, bool loop, bool reverse)
{
    Animation tmp;
    tmp.start = start;
    tmp.end = end;
    tmp.speed = speed;
    tmp.loop = loop;
    tmp.reverse = reverse;

    animation.push_back(tmp);

    return animation.size()-1;
}

void AnimatedTexture::removeAnimation(irr::u32 num)
{
    animation.erase(num);

    if(currentAnim == num) {
        currentAnim = 0;
        currentFrame = 0;
    }

    if (currentAnim > num)
        currentAnim--;
}

void AnimatedTexture::clearAnimations()
{
    animation.clear();
    currentAnim = 0;
    currentFrame = 0;
}

void AnimatedTexture::setAnimation(irr::u32 num)
{
    currentAnim = num;
    if (animation[currentAnim].reverse)
        currentFrame = animation[currentAnim].end;
    else
        currentFrame = animation[currentAnim].start;
    oldTime = Device->getTimer()->getTime();
}

irr::u32 AnimatedTexture::getCurrentAnimation()
{
    return currentAnim;
}

void AnimatedTexture::setAnimationSpeed(irr::u32 num, irr::u32 newspeed)
{
    if (animation.empty())
        return;
    else
        animation[num].speed = newspeed;
}

irr::u32 AnimatedTexture::getAnimationSpeed(irr::u32 num)
{
    return (animation.empty() ? 0 : animation[num].speed);
}

irr::u32 AnimatedTexture::getAnimationStart(irr::u32 num)
{
    return animation[num].start;
}

irr::u32 AnimatedTexture::getAnimationEnd(irr::u32 num)
{
    return animation[num].end;
}

void AnimatedTexture::setAnimationLoopState(irr::u32 num, bool loop)
{
    animation[num].loop = loop;
}

bool AnimatedTexture::getAnimationLoopState(irr::u32 num)
{
    return animation[num].loop;
}

void AnimatedTexture::reverseAnimation(irr::u32 num, bool reverse)
{
    animation[num].reverse = reverse;
}

bool AnimatedTexture::isAnimationReversed(irr::u32 num)
{
    return animation[num].reverse;
}

void AnimatedTexture::setPosition(irr::s32 x, irr::s32 y)
{
    position.LowerRightCorner = position.LowerRightCorner - position.UpperLeftCorner + irr::core::position2d<irr::s32>(x,y);
    position.UpperLeftCorner = irr::core::position2d<irr::s32>(x,y);
}

irr::core::position2d<irr::s32> AnimatedTexture::getPosition()
{
    return position.UpperLeftCorner;
}

irr::u32 AnimatedTexture::getFrameCount()
{
    return frame.size();
}

irr::u32 AnimatedTexture::getAnimationCount()
{
    return animation.size();
}

void AnimatedTexture::setTexture(irr::video::ITexture *newtexture)
{
    texture = newtexture;
}

irr::video::ITexture* AnimatedTexture::getTexture()
{
    return texture;
}

irr::core::dimension2d<irr::s32> AnimatedTexture::getSize()
{
    irr::core::dimension2d<irr::s32> size;

    size.Width = position.LowerRightCorner.X - position.UpperLeftCorner.X;
    size.Height = position.LowerRightCorner.Y - position.UpperLeftCorner.Y;

    return size;
}

irr::u32 AnimatedTexture::getCurrentFrame()
{
    return currentFrame;
}