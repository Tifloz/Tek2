/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Interface for OOP_arcade_2018
*/

#ifndef ARCADE_ISPRITE_HPP
#define ARCADE_ISPRITE_HPP

#include <string>
#include <vector>
#include "IWindows.hpp"
#include "../tools/Position.hpp"

class ISprite {
    public:
    virtual ~ISprite() = default;
    virtual bool setTexture(const std::string &pathTexture) = 0;
    virtual Position getPosition() const = 0;
    virtual bool setPosition(Position position) = 0;
    virtual bool setTransparent(size_t) = 0;
    virtual size_t getTransparent() const = 0;
    virtual bool display(void *) = 0;
    virtual bool setVector(Position) = 0;
    virtual bool deleteVector() = 0;
    virtual bool move() = 0;
    virtual bool rotate(int rotation) = 0;
    virtual bool setSize(size_t height, size_t weight) = 0;
    virtual std::vector<size_t>getSize() const = 0;
    virtual bool setScale(size_t scale) = 0;
    virtual size_t getScale() const = 0;
};

#endif //ARCADE_ISPRITE_HPP
