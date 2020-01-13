/*
** EPITECH PROJECT, 2018
** PSU_zappy_2018
** File description:
** Core.cpp
*/

#include <iostream>
#include "Core.hpp"
#include "Sprite.hpp"
#include "menu/Menu.hpp"
#include "Game/Game.hpp"

Core::~Core()
{
    for (const auto &scene : _scenes)
        delete scene.second;
}


void Core::init(int argc, char *argv[]) {
    std::string tmp;
    std::string infos;
    std::cout << "Initializing Core..." << std::endl;
    if (!parseArgs(argc, argv) || !_server.init() || !_server.connect(argv[1], std::stoi(argv[2])))
        throw ZappyError("connection initialising error");
    _window.create(sf::VideoMode(1200, 1080), "Zappy");
    _window.setFramerateLimit(60);
    _activeTab = "menu";
    _scenes["menu"] = new Menu(&_window, _activeTab, argv);
    _scenes["game"] = new Game(&_window, _activeTab, _server);
}

void Core::makeSureSceneIsReadyToGo() {
    if (!_scenes[_activeTab]->isLoaded()) {
        for (auto tab : _scenes)
            tab.second->unload();
        if (!_scenes[_activeTab]->init()) {
            std::cout << "window close" << std::endl;
            _window.close();
        }
    }
}

void Core::run()
{
    if (_scenes.empty()) {
        std::cerr << "Error: _scenes.empty() returned true, terminating the process..." << std::endl;
        return;
    }

    while (_window.isOpen()) {
        _scenes[_activeTab]->handleEvents();
        makeSureSceneIsReadyToGo();
        _scenes[_activeTab]->update();
        makeSureSceneIsReadyToGo();
        _window.clear();
        _scenes[_activeTab]->draw();
        _window.display();
    }
}

bool Core::parseArgs(int ac, char *av[])
{
    return (ac == 3 &&
        std::regex_match(av[2], std::regex("[0-9.]*$")) &&
        std::regex_match(av[2], std::regex("[0-9]*$")));
}