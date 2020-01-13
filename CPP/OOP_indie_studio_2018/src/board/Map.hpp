/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef MAP_H
#define MAP_H

#include <irrlicht/irrlicht.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#include "Cube.hpp"

class Map
{
public:
    Map();

    bool init(std::string);
    std::vector<std::string> getTiles() const;
    size_t rows() const;
    size_t cols() const;
    char &getTile(int, int);
    void setTile(int, int, char);
    void clear();
    std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> getSofts() const;
    void addSoft(std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>);
    std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> getHards() const;
    void addHard(std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>);
    std::pair<int, int> getFreeSlot();
    bool cellIsFree(int, int);
    irr::core::vector3df getPlayer(int);

    private:
    std::vector<std::string> _tiles;
    std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> _softs;
    std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> _hards;
    size_t _width;
    size_t _height;
};

#endif