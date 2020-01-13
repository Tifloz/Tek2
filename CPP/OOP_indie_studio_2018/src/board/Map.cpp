/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "../map/Generator.hpp"
#include "Map.hpp"

Map::Map() : _width(0), _height(0)
{
}

bool Map::init(std::string path)   // lecture du fichier de config et creation d'un double tableau avec les symboles
{
    std::ifstream file(path);
    std::string line;

    if (!file) {
        std::cout << "Couldn't open file : " << path << std::endl;
        Generator tmp("Map.txt");
        file = std::ifstream("Map.txt");
        if (!file)
            exit(84);
    }
    while (std::getline(file, line)) {
        if (!line.empty() && std::strspn(line.c_str(), "Xo+ 0123") != line.size()) {
            std::cout << "Corrupted Map file : " << path << std::endl;
            return false;
        }
        if (!_width)
            _width = line.size();
        else
            if (_width != line.size()) {
                std::cout << "Corrupted Map file : " << path << std::endl;
                return false;
            }
        _tiles.push_back(line);
    }
    _height = _tiles.size();
    std::reverse(_tiles.begin(), _tiles.end());
    srand(time(nullptr));
    return true;
}

std::vector<std::string> Map::getTiles() const
{
    return _tiles;
}

size_t Map::rows() const
{
    return _tiles.size();
}

size_t Map::cols() const
{
    return _tiles[0].size();
}

char &Map::getTile(int col, int row)
{
    return _tiles.at(row).at(col);
}

void Map::setTile(int col, int row, char newTile)
{
    _tiles.at(row).at(col) = newTile;
}

void Map::clear() {
    _width = 0;
    _height = 0;
    _tiles.clear();
    _softs.clear();
    _hards.clear();
}

std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> Map::getSofts() const
{
    return _softs;
}

void Map::addHard(std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *> node)
{
    _hards.push_back(node);
}

std::vector<std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *>> Map::getHards() const
{
    return _hards;
}

void Map::addSoft(std::pair<std::pair<irr::f32, irr::f32>, irr::scene::IMeshSceneNode *> node)
{
    _softs.push_back(node);
}

std::pair<int, int> Map::getFreeSlot()
{
    int x = rand() % _width;
    int y = rand() % _height;
    while (!cellIsFree(x, y)) {
        x = rand() % _width;
        y = rand() % _height;
    }
    return std::make_pair(x, y);
}

bool Map::cellIsFree(int x, int y)
{
	if (x >= static_cast<int>(rows()) || x < 0 || y >= static_cast<int>(cols()) || y < 0 )
		return false;
	if (getTile(x, y) == 'X' || getTile(x, y) == 'o')
        return false;
    if (getTile(x, y) == ' ') {
	    return true;
    }
    for (auto cell : _softs)
        if (cell.first.first == x && cell.first.second == y)
            return false;
    return true;
}

irr::core::vector3df Map::getPlayer(int id)
{
    for (size_t x = 0 ; x < _width ; x++) {
        for (size_t y = 0 ; y < _height ; y++) {
            if (_tiles[y][x] == id + 48) {
                _tiles[y][x] = ' ';
                return irr::core::vector3df(x * 10.f, y * 10.f, 0.f);
            }
        }
    }
    return irr::core::vector3df(-1.f, -1.f, 100.f);
}