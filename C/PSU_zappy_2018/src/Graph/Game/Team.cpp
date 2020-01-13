/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#include "Team.hpp"

Team::Team(const std::string &name) : _name(name)
{
}

const std::string Team::getName() const
{
    return _name;
}

void Team::addPlayer(std::vector<int> infos)
{
    _players.push_back(new Player(infos[1], infos[2], infos[3], infos[4], infos[5]));
    _players.back()->setFood(infos[6]);
    _players.back()->setLinemate(infos[7]);
    _players.back()->setDeraumere(infos[8]);
    _players.back()->setSibur(infos[9]);
    _players.back()->setMendiane(infos[10]);
    _players.back()->setPhiras(infos[11]);
    _players.back()->setThystame(infos[12]);
}

void Team::setPlayer(std::vector<int> infos)
{
    for (auto player : _players)
        if (player->getId() == infos[1]) {
            player->setY(infos[2]);
            player->setX(infos[3]);
            player->setLvl(infos[4]);
            player->setDir(infos[5]);
            player->setFood(infos[6]);
            player->setLinemate(infos[7]);
            player->setDeraumere(infos[8]);
            player->setSibur(infos[9]);
            player->setMendiane(infos[10]);
            player->setPhiras(infos[11]);
            player->setThystame(infos[12]);
        }
}

std::vector<Player *> Team::getPlayers() const
{
    return _players;
}

void Team::removePlayer(int id)
{
    auto sav = _players.end();

    for (auto it = _players.begin() ; it != _players.end() ; it++)
        if ((*it)->getId() == id)
            sav = it;
    if (sav != _players.end()) {
        delete *sav;
        _players.erase(sav);
    }
}