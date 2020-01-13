/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_PLASMARIFLE_HPP
#define CPP_D10_2018_PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
    public:
    PlasmaRifle();

    virtual ~PlasmaRifle();

    virtual void attack() const;
};

#endif //CPP_D10_2018_PLASMARIFLE_HPP
