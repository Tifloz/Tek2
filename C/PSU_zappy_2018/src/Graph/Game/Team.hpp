/*
** EPITECH PROJECT, 2019
** Graph
** File description:** Created by Denis Demouveau,
*/

#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "Player.hpp"

class Team
{
    public:
    Team(const std::string &name);

    const std::string getName() const;
    void setPlayer(std::vector<int> infos);
    void addPlayer(std::vector<int> infos);
    std::vector<Player *> getPlayers() const;
    void removePlayer(int id);

    private:
    std::string _name;
    std::vector<Player *> _players;
};

#endif