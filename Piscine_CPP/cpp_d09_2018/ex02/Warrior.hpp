/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_WARRIOR_HPP
#define CPP_D09_2018_WARRIOR_HPP

#include <iostream>
#include "Character.hpp"

class Warrior : public Character {
    public:
    Warrior(const std::string &name, int lvl);

    ~Warrior();

    int CloseAttack();

    int RangeAttack();

    private:
    std::string weaponName;
};

#endif //CPP_D09_2018_WARRIOR_HPP
