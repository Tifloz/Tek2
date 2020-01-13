/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_ARCADE_2018_SDLWINDOWS_HPP
#define OOP_ARCADE_2018_SDLWINDOWS_HPP

#include <SDL2/SDL_video.h>
#include <iostream>
#include "IWindows.hpp"

class SdlWindows : IWindows {
    public:
    ~SdlWindows();

    SdlWindows(unsigned int width, unsigned int height, std::string title);

    bool setFullsreen(bool state);

    bool setFPS(size_t fps);

    const std::string &getWindowsName() const;

    void setWindowsName(std::string name);

    bool setSize(size_t width, size_t height);

    size_t getWidth();

    size_t getHeight();

    bool clear();

    void *getWindows();

    const std::vector<lib::KEY> getEvent() const;

    private:
    SDL_Window *window;
};

#endif //OOP_ARCADE_2018_SDLWINDOWS_HPP
