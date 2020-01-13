/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_CHARACTER_HPP
#define CPP_D09_2018_CHARACTER_HPP

#include <iostream>

class Character {
    public:
    Character(const std::string &name, int level);

    ~Character();

    const std::string &getName() const;

    int getLvl() const;

    int getPv() const;

    int getPower() const;

    int CloseAttack();

    int RangeAttack();

    void Heal();

    void RestorePower();

    void TakeDamage(int _damage);

    enum AttackRange {
        CLOSE,
        RANGE
    };
    AttackRange Range;
    private:
    std::string _name;
    int _level;
    int _pv;
    int _power;
    int _strenght;
    int _stamina;
    int _intelligence;
    int _spirit;
    int _agility;
};

#endif //CPP_D09_2018_CHARACTER_HPP
