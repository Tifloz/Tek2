/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_POWERFIST_HPP
#define CPP_D10_2018_POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
    public:
    PowerFist();

    virtual ~PowerFist();

    virtual void attack() const;
};

#endif //CPP_D10_2018_POWERFIST_HPP
