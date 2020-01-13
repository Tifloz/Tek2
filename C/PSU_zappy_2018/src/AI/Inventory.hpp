/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** inventory hpp
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>

class Inventory
{
public:
    Inventory();
    ~Inventory();

    int getFood();
    int getLinemate();
    int getDeraumere();
    int getSibur();
    int getMendiane();
    int getPhiras();
    int getThystame();

    void setInventory(std::string serveurMessage);

private:
    unsigned int _food;
    unsigned int _linemate;
    unsigned int _deraumere;
    unsigned int _sibur;
    unsigned int _mendiane;
    unsigned int _phiras;
    unsigned int _thystame;
};

#endif
