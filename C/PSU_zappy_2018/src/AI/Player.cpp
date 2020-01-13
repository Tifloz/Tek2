/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** player cpp
*/

#include "Player.hpp"

Player::Player() : _level(1), _inventory(new Inventory())
{
}

Player::~Player()
{
}

int Player::getLevel()
{
    return _level;
}

Inventory *Player::getInventory()
{
    return _inventory;
}

void Player::setLevel(int n)
{
    _level = n;
}
