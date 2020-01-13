/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D14M_2018_LEMON_HPP
#define CPP_D14M_2018_LEMON_HPP

#include <iostream>
#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
    Lemon();

    virtual ~Lemon();

    virtual std::string const &getName() const;
};

#endif //CPP_D14M_2018_LEMON_HPP
