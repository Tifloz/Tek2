/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_PRIEST_HPP
#define CPP_D09_2018_PRIEST_HPP

#include "Mage.hpp"

class Priest : public Mage {
    public:
    Priest(const std::string &name, int level);

    ~Priest();

    int CloseAttack();

    void Heal();
};

#endif //CPP_D09_2018_PRIEST_HPP
