/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_SUPERMUTANT_HPP
#define CPP_D10_2018_SUPERMUTANT_HPP

#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
    public:
    SuperMutant();

    virtual ~SuperMutant();

    virtual void takeDamage(int damage);
};

#endif //CPP_D10_2018_SUPERMUTANT_HPP
