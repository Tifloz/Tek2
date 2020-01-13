/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Scene.hpp
*/

#ifndef GRAPH_SCENE_HPP
#define GRAPH_SCENE_HPP

#include <SFML/Graphics.hpp>

class Scene {
public:
    Scene(sf::RenderWindow *window, std::string &_activeTab);

    virtual ~Scene();

    virtual bool init() = 0;

    virtual void update() = 0;

    virtual void draw() = 0;

    virtual void handleEvents() = 0;

    bool isLoaded() const;

    virtual void unload();

protected:
    sf::RenderWindow *_window;
    std::string &_activeTab;
    bool _loaded = false;
};

#endif //GRAPH_SCENE_HPP
