/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#ifndef MAP_H
#define MAP_H

#include <vector>

struct Tile {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

class Map
{
    public:
    Map();

    bool init(int x, int y);
    void setTile(int x, int y, Tile infos);
    int getHeight() const;
    int getWidth() const;

private:
    int _width;
    int _height;
    std::vector<std::vector<Tile>> _tiles;
public:
    const std::vector<std::vector<Tile>> &getTiles() const;
};

#endif