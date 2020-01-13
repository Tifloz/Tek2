/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <vector>
#include "Bomb.hpp"
#include "Map.hpp"
#include "Entity.hpp"
#include "Powerup.hpp"

class Player : public Entity
{
public:
    Player(int, irr::IrrlichtDevice *, const irr::io::path &,
        const irr::core::vector3df &, bool, irr::scene::IMetaTriangleSelector *,
        AudioManager *
    );
    ~Player();

    bool isAlive() const;
    bool isHuman() const;
    void setAction(const std::string&, bool);
    void update(std::vector<Bomb *> &, std::vector<Powerup *> &);
    void setAlive(bool);
    bool hasBombs(std::vector<Bomb *> &) const;
    int getId() const;
    void handlePowerups(std::vector<Powerup *> &);

protected:
    int _id;
    bool _alive;
    bool _human;
    std::map<std::string, bool> _actions;
    std::map<Powerup::Type, std::pair<bool, irr::u32>> _buffs;
    bool _placingBomb = false;
};

#endif