/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_TACTICALMARINE_HPP
#define CPP_D10_2018_TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
    public:
    TacticalMarine();

    TacticalMarine(const TacticalMarine &marine);

    virtual ~TacticalMarine();

    virtual ISpaceMarine *clone() const;

    virtual void battleCry() const;

    virtual void rangedAttack() const;

    virtual void meleeAttack() const;
};

#endif //CPP_D10_2018_TACTICALMARINE_HPP
