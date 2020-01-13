/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** AnimatedTexture.hpp
*/

#ifndef INDIE_STUDIO_ANIMATEDTEXTURE_HPP
#define INDIE_STUDIO_ANIMATEDTEXTURE_HPP

#include <irrlicht/irrlicht.h>
#include <iostream>

class AnimatedTexture
{
private:
    struct Animation
    {
        irr::s32 start;
        irr::s32 end;
        irr::u32 speed;
        bool loop;
        bool reverse;
    };
    irr::video::ITexture *texture;
    irr::core::array<irr::core::rect<irr::s32>> frame;
    irr::s32 currentFrame;
    irr::core::rect<irr::s32> position;
    irr::core::array<Animation> animation;
    irr::u32 currentAnim;
    irr::u32 oldTime;
    irr::IrrlichtDevice *Device;
    irr::f32 _scaleX = 1.f;
    irr::f32 _scaleY = 1.f;

public:
    AnimatedTexture() {};
    AnimatedTexture(irr::IrrlichtDevice *idevice, irr::video::ITexture *itexture, irr::s32 divX = 1, irr::s32 divY = 1);

    AnimatedTexture(AnimatedTexture &other);

    ~AnimatedTexture(){}

    virtual void draw(irr::u32 num = 0);

    virtual void play();

    virtual irr::u32 addAnimation(irr::u32 start, irr::u32 end, irr::u32 speed, bool loop = false, bool reverse = false);

    virtual void removeAnimation(irr::u32 num);

    virtual void clearAnimations();

    virtual void setAnimation(irr::u32 num);

    virtual irr::u32 getCurrentAnimation();

    virtual void setAnimationSpeed(irr::u32 num, irr::u32 newspeed);

    virtual irr::u32 getAnimationSpeed(irr::u32 num);

    virtual irr::u32 getAnimationStart(irr::u32 num);

    virtual irr::u32 getAnimationEnd(irr::u32 num);

    virtual void setAnimationLoopState(irr::u32 num, bool loop);

    virtual bool getAnimationLoopState(irr::u32 num);

    virtual void reverseAnimation(irr::u32 num, bool reverse);

    virtual bool isAnimationReversed(irr::u32 num);

    virtual void setPosition(irr::s32 x, irr::s32 y);

    virtual irr::core::position2d<irr::s32> getPosition();

    virtual irr::u32 getFrameCount();

    virtual irr::u32 getAnimationCount();

    virtual void setTexture(irr::video::ITexture *newtexture);

    virtual irr::video::ITexture* getTexture();

    virtual irr::core::dimension2d<irr::s32> getSize();

    virtual irr::u32 getCurrentFrame();

    virtual void setScale(irr::f32 scaleX, irr::f32 scaleY);
};

#endif //INDIE_STUDIO_ANIMATEDTEXTURE_HPP
