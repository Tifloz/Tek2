/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_ASSAULTTERMINATOR_HPP
#define CPP_D10_2018_ASSAULTTERMINATOR_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
    public:
    AssaultTerminator();

    AssaultTerminator(const AssaultTerminator &marine);

    virtual ~AssaultTerminator();

    virtual ISpaceMarine *clone() const;

    virtual void battleCry() const;

    virtual void rangedAttack() const;

    virtual void meleeAttack() const;
};

#endif //CPP_D10_2018_ASSAULTTERMINATOR_HPP
