/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#ifndef GAME_H
#define GAME_H

#include "../Scene.hpp"
#include "../Socket.hpp"
#include "../Sprite.hpp"
#include "Team.hpp"
#include "Map.hpp"

class Game : public Scene
{
public:
    Game(sf::RenderWindow *window, std::string &activeTab, Socket &server);

    bool init() override;
    void update() override;
    void draw() override;
    void unload() override;
    void handleEvents() override;
    void handleCommand(const std::string &line);
    std::vector<std::string> explode(const std::string& str, const char& ch);


    bool msz(const std::string &line);
    bool bct(const std::string &line);
    bool tna(const std::string &line);
    bool pp(const std::string &line);
    bool pdi(const std::string &line);

private:
    sf::Event _event;
    Socket &_server;
    Map _map;
    std::vector<Team *> _teams;
    std::map<std::string, Sprite *> _sprites;

    std::vector<Sprite *> _food;
    std::vector<Sprite *> _linemate;
    std::vector<Sprite *> _deraumere;
    std::vector<Sprite *> _sibur;
    std::vector<Sprite *> _mendiane;
    std::vector<Sprite *> _phiras;
    std::vector<Sprite *> _thystame;

    std::vector<Sprite *> _tiles;
    Sprite *_selector;
    Sprite *_selector2;
    Sprite *_peekMenu;
    bool _peekRessources = false;
    Tile selectedTile;
    sf::Font _font;
    sf::View _orig;
    sf::View _view;
    std::map<std::string, sf::Text> _texts;
    std::string _infos;
    char *argv[];
};

#endif