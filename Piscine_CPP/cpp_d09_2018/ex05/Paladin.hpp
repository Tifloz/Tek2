/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_PALADIN_HPP
#define CPP_D09_2018_PALADIN_HPP

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest {
    public:
    Paladin(const std::string &name, int level);

    ~Paladin();

    int CloseAttack();

    int RangeAttack();

    void Heal();

    void RestorePower();

    int Intercept();
};

#endif //CPP_D09_2018_PALADIN_HPP
