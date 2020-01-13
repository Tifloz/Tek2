/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D14M_2018_FRUITBOX_HPP
#define CPP_D14M_2018_FRUITBOX_HPP

#include <iostream>
#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
    public:
    FruitBox(int size);

    virtual ~FruitBox();

    int nbFruits() const;

    bool putFruit(Fruit *f);

    Fruit *pickFruit();

    FruitNode *head() const;

    protected:
    int _size;
    int _count;
    FruitNode *header;
};

#endif //CPP_D14M_2018_FRUITBOX_HPP
