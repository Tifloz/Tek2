/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Sprite.cpp
*/

#include <iostream>
#include <vector>
#include "Sprite.hpp"
#include "Error.hpp"

Sprite::Sprite(sf::RenderWindow *window, std::string path, int divX, int divY) {
    _window = window;
    if (!_texture.loadFromFile(path)) {
        throw ZappyError("Sprite '" + path + "' did not load properly, aborting...");
    }
    _sprite.setTexture(_texture);
    auto spriteSize = (_texture.getSize());
    spriteSize.x = spriteSize.x / divX;
    spriteSize.y = spriteSize.y / divY;

    int n = 0;
    for (int j = 0; j < divY; j++)
        for(int i = 0; i < divX; i++) {
            sf::Vector2i position(i * spriteSize.x, j * spriteSize.y);
            sf::Vector2i size(spriteSize.x, spriteSize.y);
            sf::IntRect rect(position, size);
            _frame.push_back(rect);
            n++;
        }

    _currentFrame = 0;
    _currentAnim = 0;
    _position = {0, 0, static_cast<int>(spriteSize.x), static_cast<int>(spriteSize.y)};
    _sprite.setTextureRect(_frame[_currentFrame]);
}

Sprite::~Sprite() {

}

sf::Sprite Sprite::getSprite() const { return _sprite; }

int Sprite::addAnimation(int start, int end, int speed, bool loop, bool reverse)
{
    Animation tempAnim;
    tempAnim.start = start;
    tempAnim.end = end;
    tempAnim.speed = speed;
    tempAnim.loop = loop;
    tempAnim.reverse = reverse;

    _animations.push_back(tempAnim);

    return _animations.size() - 1;
}

void Sprite::setAnimation(int num)
{
    _currentAnim = num;
    if (_animations[_currentAnim].reverse)
        _currentFrame = _animations[_currentAnim].end;
    else
        _currentFrame = _animations[_currentAnim].start;
}

void Sprite::setPosition(sf::Vector2f position) {
    _sprite.setPosition(position);
}

sf::Vector2f Sprite::getPosition() const { return _sprite.getPosition(); }

void Sprite::setNextFrame()
{
    if (_animations.empty()) {
        _currentFrame = 0;
        return;
    }
    if (_clock.getElapsedTime().asMilliseconds() > _animations[_currentAnim].speed) {
        if (_animations[_currentAnim].reverse) {
            _currentFrame -= 1;
            if (_currentFrame < _animations[_currentAnim].start) {
                if (_animations[_currentAnim].loop)
                    _currentFrame = _animations[_currentAnim].end;
                else
                    _currentFrame += 1;
            }
        } else {
            _currentFrame += 1;

            if (_currentFrame > _animations[_currentAnim].end) {
                if (_animations[_currentAnim].loop)
                    _currentFrame = _animations[_currentAnim].start;
                else
                    _currentFrame -= 1;
            }

            _clock.restart();
        }
    }
    _sprite.setTextureRect(_frame[_currentFrame]);
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

int Sprite::getCurrentAnimation() const { return _currentAnim; }

void Sprite::setAnimationSpeed(int num, int newspeed)
{
    if (_animations.empty())
        return;
    else
        _animations[num].speed = newspeed;
}

int Sprite::getAnimationSpeed(int num) { return (_animations.empty() ? 0 : _animations[num].speed); }

int Sprite::getAnimationStart(int num) { return _animations[num].start; }

int Sprite::getAnimationEnd(int num) { return _animations[num].end; }

void Sprite::removeAnimation(int num)
{
    _animations.erase(_animations.begin() + num - 1);

    if(_currentAnim == num) {
        _currentAnim = 0;
        _currentFrame = 0;
    }

    if (_currentAnim > num)
        _currentAnim--;
}

void Sprite::clearAnimations()
{
    _animations.clear();
    _currentAnim = 0;
    _currentFrame = 0;
}

void Sprite::setScale(sf::Vector2f scale) {
    _sprite.setScale(scale);
}

sf::Vector2f Sprite::getScale() const { return _sprite.getScale(); }

Sprite::Sprite() {

}

Sprite::Sprite(const Sprite &other) {
    _window = other._window;
    _texture = other._texture;
    _sprite = other._sprite;
    _clock = other._clock;
    _frame = other._frame;
    _currentFrame = other._currentFrame;
    _currentAnim = other._currentAnim;
    _position = other._position;
    _animations = other._animations;
    _sprite.setTexture(other._texture);
}

sf::Texture Sprite::getTexture() const {
    return _texture;
}

int Sprite::getCurrentFrame() const {
    return _currentFrame;
}

