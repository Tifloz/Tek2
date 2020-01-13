/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_CHARACTER_HPP
#define CPP_D10_2018_CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
    Character(std::string const &name);

    virtual ~Character();

    void recoverAP();

    void equip(AWeapon *weapon);

    void attack(AEnemy *enemy);

    std::string const &getName() const;

    int getAP() const;

    AWeapon *getWeapon() const;

    protected:
    std::string _name;
    int _hp;
    int _ap;
    AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &os, Character const &elem);

#endif //CPP_D10_2018_CHARACTER_HPP
