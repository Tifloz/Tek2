/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D13_2018_BUZZ_HPP
#define CPP_D13_2018_BUZZ_HPP

#include <iostream>
#include "Toy.hpp"

class Buzz : public Toy {
    public:
    Buzz(std::string const &name, std::string const &filename = "buzz.txt");

    virtual ~Buzz();
};

#endif //CPP_D13_2018_BUZZ_HPP
