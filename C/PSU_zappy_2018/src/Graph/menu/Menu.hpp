/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Menu.hpp
*/

#ifndef GRAPH_MENU_HPP
#define GRAPH_MENU_HPP

#include "../Scene.hpp"
#include "../Sprite.hpp"
#include "button/Button.hpp"

class Menu: public Scene {
public:
    Menu(sf::RenderWindow *window, std::string &activeTab, char **pString);

    ~Menu();

    bool init() override;

    void update() override;

    void draw() override;

    void unload() override;

    void handleEvents() override;
private:
    sf::Event _event;
    sf::Font _font;
    std::map<std::string, sf::Text> _texts;
    std::map<std::string, Sprite *> _sprites;
    std::map<std::string, Button *> _buttons;
    bool _playTransition = false;
    char **_argv;
};

#endif //GRAPH_MENU_HPP
