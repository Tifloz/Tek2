/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** player hpp
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Inventory.hpp"

class Player
{
public:
    Player();
    ~Player();

    int getLevel();
    void setLevel(int n);
    Inventory *getInventory();

private:
    int _level;
    Inventory *_inventory;
};

#endif
