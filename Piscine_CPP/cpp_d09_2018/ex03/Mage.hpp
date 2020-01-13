/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_MAGE_HPP
#define CPP_D09_2018_MAGE_HPP

#include "Character.hpp"

class Mage : public Character {
    public:
    Mage(const std::string &name, int level);

    ~Mage();

    int CloseAttack();

    int RangeAttack();

    void RestorePower();
};

#endif //CPP_D09_2018_MAGE_HPP
