/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#include "SdlWindows.hpp"

SdlWindows::~SdlWindows()
{
}

SdlWindows::SdlWindows(unsigned int width, unsigned int height,
    std::string title
) : window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE))
{
}

bool SdlWindows::setFullsreen(bool state)
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    return true;
}

bool SdlWindows::setFPS(size_t fps)
{
    //TODO: Faire cette fonction
    return false;
}

const std::string &SdlWindows::getWindowsName() const
{
    return SDL_GetWindowTitle(window);
}

void SdlWindows::setWindowsName(std::string name)
{
    SDL_SetWindowTitle(window, name.c_str());
}

bool SdlWindows::setSize(size_t width, size_t height)
{
    SDL_SetWindowSize(window, static_cast<int>(width),
        static_cast<int>(height));
    return true;
}

size_t SdlWindows::getWidth()
{
    return static_cast<size_t>(SDL_GetWindowSurface(window)->w);
}

size_t SdlWindows::getHeight()
{
    return static_cast<size_t>(SDL_GetWindowSurface(window)->h);
}

bool SdlWindows::clear()
{
    return false;
}

SDL_Window *SdlWindows::getWindows()
{
    return (this->window);
}

const std::vector<lib::KEY> SdlWindows::getEvent() const
{
    return std::vector<lib::KEY>();
}
