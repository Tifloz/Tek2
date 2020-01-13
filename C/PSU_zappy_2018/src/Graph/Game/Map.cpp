/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#include "Map.hpp"

Map::Map() : _width(0), _height(0)
{
}

bool Map::init(int x, int y)
{
    _width = x;
    _height = y;
    for (int i = 0 ; i < y ; i++) {
        std::vector<Tile> vec;
        vec.resize(x, {0, 0, 0, 0, 0, 0, 0});
        _tiles.push_back(vec);
    }
    return true;
}

void Map::setTile(int x, int y, Tile infos)
{
    _tiles.at(y).at(x) = infos;
}

int Map::getWidth() const {
    return _width;
}

int Map::getHeight() const {
    return _height;
}

const std::vector<std::vector<Tile>> &Map::getTiles() const {
    return _tiles;
}
