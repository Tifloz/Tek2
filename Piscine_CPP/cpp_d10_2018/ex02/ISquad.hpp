/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_ISQUAD_HPP
#define CPP_D10_2018_ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad {
    public:
    virtual ~ISquad() = default;

    virtual int getCount() const = 0;

    virtual ISpaceMarine *getUnit(int) = 0;

    virtual int push(ISpaceMarine *) = 0;
};

#endif //CPP_D10_2018_ISQUAD_HPP
