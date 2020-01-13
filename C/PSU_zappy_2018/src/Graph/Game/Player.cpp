/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#include "Player.hpp"

Player::Player(int id, int y, int x, int lvl, int dir) :
_id(id), _lvl(lvl), _x(x), _y(y), _dir(dir),
_food(0), _linemate(0), _deraumere(0), _sibur(0), _mendiane(0), _phiras(0), _thystame(0), _casting(false)
{
    s_init = false;
}

void Player::initSprite(sf::RenderWindow *window, std::string path, int x, int y)
{
    _sprite = new Sprite(window, path, x, y);
    _sprite->addAnimation(0, 2, 200, true, false);
    _sprite->setAnimation(0);
    _sprite->setScale({2, 2});
    s_init = true;
}

std::vector<int> Player::getStock() const
{
    return {_food, _linemate, _deraumere, _sibur, _mendiane, _phiras, _thystame};
}

void Player::setInfos(std::vector<int> infos)
{
    _id = infos[0];
    _y = infos[1];
    _x = infos[2];
    _lvl = infos[3];
    _dir = infos[4];
}

void Player::setStock(std::vector<int> stock)
{
    _food = stock[0];
    _linemate = stock[1];
    _deraumere = stock[2];
    _sibur = stock[3];
    _mendiane = stock[4];
    _phiras = stock[5];
    _thystame = stock[6];
}