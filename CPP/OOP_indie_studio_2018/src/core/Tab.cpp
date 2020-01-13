/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Tab.hpp"

Tab::Tab(irr::IrrlichtDevice *device, std::string &activTab,
    AudioManager *AudioManager
) : _device(device), _driver(device->getVideoDriver()),
    _gui(device->getGUIEnvironment()), _activTab(activTab), _loaded(false),
    _AudioManager(AudioManager)
{
}

Tab::~Tab()
{
}

bool Tab::isLoaded() const
{
    return _loaded;
}

void Tab::unload()
{
    _loaded = false;
}

bool Tab::hasGui() const {
    return _hasGui;
}
