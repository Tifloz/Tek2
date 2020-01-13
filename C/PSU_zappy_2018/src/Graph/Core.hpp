/*
** EPITECH PROJECT, 2018
** PSU_zappy_2018
** File description:
** Core.hpp
*/

#ifndef PSU_ZAPPY_2018_GRAPH_HPP
#define PSU_ZAPPY_2018_GRAPH_HPP

#include <string>
#include <map>
#include <regex>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Socket.hpp"
#include "Error.hpp"

class Core
{
public:
    Core() = default;
    ~Core();
    void run();
    void init(int argc, char *argv[]);

    bool hasEnded(std::string);

private:
    void makeSureSceneIsReadyToGo();
    bool parseArgs(int ac, char **av);

    Socket _server;
    std::string _activeTab = "menu";
    std::map<std::string, Scene *> _scenes;
    sf::RenderWindow _window;
};

#endif //PSU_ZAPPY_2018_GRAPH_HPP
