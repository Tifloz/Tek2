/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Interface for OOP_arcade_2018    
*/

#ifndef ARCADE_ITEXT_HPP
#define ARCADE_ITEXT_HPP

#include <string>
#include <vector>
#include "ILibrary.hpp"
#include "../tools/Position.hpp"
#include "IWindows.hpp"

class Itext {
    public:
        virtual ~Itext() = default;
        virtual bool set(std::string text) = 0;
        virtual std::string getColor() const = 0;
        virtual bool setColor(std::string color) = 0;
        virtual size_t getSize() const = 0;
        virtual bool setSize(size_t size) = 0;
        virtual Position getPosition() const = 0;
        virtual bool setPosition(Position position) = 0;
        virtual bool display(void *) = 0;
        virtual bool setFont(std::string) = 0;
};

#endif //ARCADE_ISPRITE_HPP
