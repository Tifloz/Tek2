/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Image.hpp"
#include <iostream>

Image::Image(irr::video::IVideoDriver *driver, const irr::io::path& filename, irr::core::position2d<irr::s32> pos,
    irr::core::rect<irr::s32> rect, irr::video::SColor color) :
_driver(driver), _pos(pos), _rect(rect), _color(color)
{
    _texture = _driver->getTexture(filename);
}

void Image::draw()
{
    _driver->draw2DImage(_texture, _pos, _rect, 0, _color, true);
}

void Image::setRectangle(irr::core::rect<irr::s32> rectangle) {
    _rect = rectangle;
}

void Image::move(irr::core::position2d<irr::s32> position)
{
    _pos += position;
}