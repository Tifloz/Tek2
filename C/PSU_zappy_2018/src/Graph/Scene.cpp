/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

Scene::Scene(sf::RenderWindow *window, std::string &activeTab) : _window(window), _activeTab(activeTab) {}

Scene::~Scene() {}

bool Scene::isLoaded() const { return _loaded; }

void Scene::unload() {
    _loaded = false;
}
