/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../Sprite.hpp"

class Player
{
    public:
    Player(int id, int y, int x, int lvl = 1, int dir = 0);

    void setY(int y) { _y = y; };
    void setX(int x) { _x = x; };
    void setLvl(int lvl) { _lvl = lvl; };
    void setDir(int dir) { _dir = dir; };
    void setFood(int food) { _food = food; };
    void setLinemate(int linemate) { _linemate = linemate; };
    void setDeraumere(int deraumere) { _deraumere = deraumere; };
    void setSibur(int sibur) { _sibur = sibur; };
    void setMendiane(int mendiane) { _mendiane = mendiane; };
    void setPhiras(int phiras) { _phiras = phiras; };
    void setThystame(int thystame) { _thystame = thystame; };
    void setCasting(bool casting) { _casting = casting; };


    int getId() const { return _id; };
    int getY() const { return _y; };
    int getX() const { return _x; };
    int getLvl() const { return _lvl; };
    int getDir() const { return _dir; };
    int getFood() const { return _food; };
    int getLinemate() const { return _linemate; };
    int getDeraumere() const { return _deraumere; };
    int getSibur() const { return _sibur; };
    int getMendiane() const { return _mendiane; };
    int getPhiras() const { return _phiras; };
    int getThystame() const { return _thystame ;};
    bool getCasting() const { return _casting; };


    std::vector<int> getStock() const;
    void setStock(std::vector<int> stock);
    void setInfos(std::vector<int> infos);

    bool s_init;
    Sprite *_sprite;
    void initSprite(sf::RenderWindow *, std::string, int, int);

    private:
    int _id;
    int _lvl;
    int _x;
    int _y;
    int _dir;
    int _food;
    int _linemate;
    int _deraumere;
    int _sibur;
    int _mendiane;
    int _phiras;
    int _thystame;
    bool _casting;
};

#endif