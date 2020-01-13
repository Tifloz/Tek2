/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D14M_2018_BANANA_HPP
#define CPP_D14M_2018_BANANA_HPP

#include <iostream>
#include "Fruit.hpp"

class Banana : public Fruit {
    public:
    Banana();

    virtual ~Banana();

    virtual std::string const &getName() const;
};

#endif //CPP_D14M_2018_BANANA_HPP
