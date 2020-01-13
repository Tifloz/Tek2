/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** inventory cpp
*/

#include "Inventory.hpp"

Inventory::Inventory() : _food(10), _linemate(0), _deraumere(0), _sibur(0), _mendiane(0), _phiras(0), _thystame(0)
{
}

Inventory::~Inventory()
{
}

int Inventory::getFood()
{
    return _food;
}

int Inventory::getLinemate()
{
    return _linemate;
}

int Inventory::getDeraumere()
{
    return _deraumere;
}

int Inventory::getSibur()
{
    return _sibur;
}

int Inventory::getMendiane()
{
    return _mendiane;
}

int Inventory::getPhiras()
{
    return _phiras;
}

int Inventory::getThystame()
{
    return _thystame;
}

void Inventory::setInventory(std::string serveurMessage)
{
    int i;
    std::string element[7];

    for (i = 6; serveurMessage[i] != ','; i++)
            element[0] = element[0] + serveurMessage[i];
    _food = std::stoi(element[0]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ','; i++)
            element[1] = element[1] + serveurMessage[i];
    _linemate = std::stoi(element[1]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ','; i++)
            element[2] = element[2] + serveurMessage[i];
    _deraumere = std::stoi(element[2]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ','; i++)
            element[3] = element[3] + serveurMessage[i];
    _sibur = std::stoi(element[3]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ','; i++)
            element[4] = element[4] + serveurMessage[i];
    _mendiane = std::stoi(element[4]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ','; i++)
            element[5] = element[5] + serveurMessage[i];
    _phiras = std::stoi(element[5]);

    for (;serveurMessage[i] < '0' || serveurMessage[i] > '9';i++);
    for (; serveurMessage[i] != ']'; i++)
            element[6] = element[6] + serveurMessage[i];
    _thystame = std::stoi(element[6]);
}
