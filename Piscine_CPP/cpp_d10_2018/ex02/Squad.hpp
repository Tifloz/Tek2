/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D10_2018_SQUAD_HPP
#define CPP_D10_2018_SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
    public:
    Squad();

    Squad(Squad const &squad);

    virtual ~Squad();

    int getCount() const;

    ISpaceMarine *getUnit(int pos);

    int push(ISpaceMarine *marine);

    Squad &operator=(const Squad &squad);

    protected:
    int _count;
    int _size;
    ISpaceMarine **_array;

    void resize();
};

#endif //CPP_D10_2018_SQUAD_HPP
