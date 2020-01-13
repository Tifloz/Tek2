/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Button.cpp
*/

#include <Error.hpp>
#include "Button.hpp"

Button::Button(std::string texturePath, std::string hoveredTexturePath, __attribute__((unused))std::string clickedTexturePath)
{
    if (!_texture.loadFromFile(texturePath)) {
        throw ZappyError("Texture '" + texturePath + "' did not load properly, aborting...");
    }
    if (!_hoveredTexture.loadFromFile(hoveredTexturePath)) {
        throw ZappyError("Texture '" + texturePath + "' did not load properly, aborting...");
    }
    _sprite.setTexture(_texture);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

Button::~Button() {

}