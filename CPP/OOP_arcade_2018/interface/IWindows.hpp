/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Interface for OOP_arcade_2018
*/

#ifndef ARCADE_IWINDOWS_HPP
#define ARCADE_IWINDOWS_HPP

#include <cstddef>
#include <string>
#include <vector>
#include "ILibrary.hpp"

class IWindows {
    public:
        virtual bool setFullsreen(bool state) = 0;
        virtual bool setFPS(size_t fps) = 0;
        virtual bool setWindowsName(const std::string &name) = 0;
        virtual bool setSize(size_t width, size_t height) = 0;
        virtual size_t getWidth() const = 0;
        virtual size_t getHeight() const = 0;
        virtual bool clear() = 0;
        virtual void *getWindows() const = 0;
        virtual const std::vector<lib::KEY> getEvent() const = 0;
        virtual void refresh() const = 0;
        virtual ~IWindows() = default;
};

#endif //ARCADE_IWINDOWS_HPP