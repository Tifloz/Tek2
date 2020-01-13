/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** ai hpp
*/

#ifndef AI_H
#define AI_H

#include "Player.hpp"
#include "Commands.hpp"

class Ai
{
public:
    Ai();
    ~Ai();

    std::vector<std::string> getToDo();
    void setToDo(std::string command);

    void chooseNextCommand(Commands *commands);

private:
    std::vector<std::string> _toDo;
};

#endif
