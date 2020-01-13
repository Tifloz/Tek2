/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_ARCADE_2018_SDLSPRITE_HPP
#define OOP_ARCADE_2018_SDLSPRITE_HPP

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_image.h>
#include "ISprite.hpp"
#include "Position.hpp"

class SdlSprite : ISprite {
    public:

    ~SdlSprite() = default;

    SdlSprite(std::string pathTexture);

    SDL_Texture *getTexture();

    bool setTexture(const std::string &pathTexture);

    Position getPosition() const;

    bool setPosition(Position position);

    bool setTransparent(size_t);

    size_t getTransparent();

    bool display(SDL_Window *);

    bool setVector(Position position);

    bool deleteVector();

    bool move();

    bool rotate(int rotation);

    bool setSize(size_t height, size_t weight);

    std::vector<int> getSize();

    private:
    SDL_Texture *texture;
    SDL_Texture *sprite;
    Position position;
    Position vector;
    SDL_Renderer *renderer;
};

#endif //OOP_ARCADE_2018_SDLSPRITE_HPP
