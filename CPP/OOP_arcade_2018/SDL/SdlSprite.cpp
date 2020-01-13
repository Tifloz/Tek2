/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#include "SdlSprite.hpp"

SdlSprite::SdlSprite(std::string pathTexture) : position(Position(0, 0)),
    vector(Position(0, 0))
{
}

SDL_Texture *SdlSprite::getTexture()
{
    return texture;
}

bool SdlSprite::setTexture(const std::string &pathTexture)
{
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(pathTexture.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n",
            pathTexture.c_str(), IMG_GetError());
    } else {
        //TODO: Modifier pour avoir une window
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n",
                pathTexture.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

Position SdlSprite::getPosition() const
{
    return position;
}

bool SdlSprite::setPosition(Position positions)
{
    position = positions;
    this->sprite.setPosition(positions.x, positions.y);
    return true;}

bool SdlSprite::setTransparent(size_t)
{
    return false;
}

size_t SdlSprite::getTransparent()
{
    return 0;
}

bool SdlSprite::display(SDL_Window * window)
{
    return false;
}

bool SdlSprite::setVector(Position position)
{
    return false;
}

bool SdlSprite::deleteVector()
{
    return false;
}

bool SdlSprite::move()
{
    return false;
}

bool SdlSprite::rotate(int rotation)
{
    return false;
}

bool SdlSprite::setSize(size_t height, size_t weight)
{
    return false;
}

std::vector<int> SdlSprite::getSize()
{
    return std::vector<int>();
}
