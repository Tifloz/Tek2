/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <iostream>
#include <Error.hpp>

Menu::Menu(sf::RenderWindow *window, std::string &activeTab, char **argv) : Scene(window, activeTab) {
    std::cout << "Constructing Menu..." << std::endl;
    _argv = argv;
}

Menu::~Menu() {
    std::cout << "Destructing Menu..." << std::endl;
}

bool Menu::init() {
    std::cout << "Initializing Menu..." << std::endl;
    if (!_font.loadFromFile("assets/font.ttf"))
        throw ZappyError("The font 'assets/font.ttf did not load properly, aborting...'");
    std::string connectedTo = std::string("Connected to IP: ") + _argv[1] + ":" + _argv[2];
    _texts["IP"] = sf::Text(connectedTo, _font, 35);
    _sprites["check"] = new Sprite(_window, "assets/check.png", 1, 1);
    _sprites["check"]->setScale({0.15, 0.15});
    _sprites["check"]->setPosition({10, 10});

    _sprites["background"] = new Sprite(_window, "assets/menu_background.jpg", 1, 1);

    _sprites["transition"] = new Sprite(_window, "assets/transition.png", 6, 7);
    _sprites["transition"]->addAnimation(0, 41, 30, false, false);
    _sprites["transition"]->setAnimation(0);
    _sprites["transition"]->setScale({1.5, 1.7});

    _texts["IP"].setPosition({_sprites["check"]->getSprite().getGlobalBounds().left + _sprites["check"]->getSprite().getGlobalBounds().width + 10, _sprites["check"]->getSprite().getGlobalBounds().top});

    _buttons["play"] = new Button("assets/button_play.png", "assets/button_play_hover.png", "");
    _buttons["play"]->_sprite.setPosition(20, 600);

    _buttons["quit"] = new Button("assets/button_quit.png", "assets/button_quit_hover.png", "");
    _buttons["quit"]->_sprite.setPosition(20, 800);

    _loaded = true;
    return true;
}

void Menu::update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*_window);
    for (auto &button: _buttons) {
        if (button.second->_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            button.second->_sprite.setTexture(button.second->_hoveredTexture);
        } else {
            button.second->_sprite.setTexture(button.second->_texture);
        }
    }

    if (_playTransition) {
        if (_sprites["transition"]->getCurrentFrame() > 16) {
            _activeTab = "game";
        }
        _sprites["transition"]->setNextFrame();
    }
}

void Menu::draw() {
    for (const auto &sprite: _sprites)
        if (sprite.first != "transition")
            _window->draw(*sprite.second);
    for (const auto &text: _texts)
        _window->draw(text.second);
    for (const auto &button: _buttons)
        _window->draw(*button.second);

    if (_playTransition) {
        _window->draw(*_sprites["transition"]);
    }
}

void Menu::unload() {
    std::cout << "Unloading Menu..." << std::endl;
    _loaded = false;
}

void Menu::handleEvents() {
    while (_window->pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window->close();
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::MouseButtonReleased:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*_window);
                if (_buttons["play"]->_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    _playTransition = true;
                }
                if (_buttons["quit"]->_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    _window->close();
                }
                break;
            }
            default:
                break;
        }
    }
}
