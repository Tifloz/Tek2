/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_AWEAPON_HPP
#define CPP_D10_2018_AWEAPON_HPP

#include <iostream>

class AWeapon {
    public:
    AWeapon(std::string const &name, int apcost, int damage);

    virtual ~AWeapon();

    std::string const &getName() const;

    int getAPCost() const;

    int getDamage() const;

    virtual void attack() const = 0;

    protected:
    std::string _name;
    int _apcost;
    int _damage;
};

#endif //CPP_D10_2018_AWEAPON_HPP
