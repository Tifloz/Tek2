/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D14M_2018_FRUITNODE_HPP
#define CPP_D14M_2018_FRUITNODE_HPP

#include "Fruit.hpp"

struct FruitNode {
    Fruit *_fruit;
    FruitNode *next;
};
#endif //CPP_D14M_2018_FRUITNODE_HPP
