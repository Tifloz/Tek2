/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <irrlicht/irrlicht.h>

class Image
{
public:
    Image(irr::video::IVideoDriver *,
        const irr::io::path &,
        irr::core::position2d<irr::s32>,
        irr::core::rect<irr::s32>,
        irr::video::SColor);

    void draw();
    void setRectangle(irr::core::rect<irr::s32> rectangle);
    void move(irr::core::position2d<irr::s32> position);
    void moveRect(irr::core::position2d<irr::s32> position)
    {
        _rect.UpperLeftCorner += position;
    }

private:
    irr::video::IVideoDriver *_driver;
    irr::video::ITexture *_texture;
    irr::core::position2d<irr::s32> _pos;
    irr::core::rect<irr::s32> _rect;
    irr::video::SColor _color;
};

#endif