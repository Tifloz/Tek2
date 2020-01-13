/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_HUNTER_HPP
#define CPP_D09_2018_HUNTER_HPP

#include "Warrior.hpp"

class Hunter : protected Warrior {
    public:
    Hunter(const std::string &name, int level);

    ~Hunter();

    int CloseAttack();

    int RangeAttack();

    void Heal();

    void RestorePower();
};

#endif //CPP_D09_2018_HUNTER_HPP
