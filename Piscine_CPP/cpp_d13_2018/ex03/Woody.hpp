/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D13_2018_WOODY_HPP
#define CPP_D13_2018_WOODY_HPP

#include "Toy.hpp"
#include <iostream>

class Woody : public Toy {
    public:
    Woody(std::string const &name, std::string const &filename = "woody.txt");

    virtual ~Woody();

    virtual void speak(const std::string &message);
};

#endif //CPP_D13_2018_WOODY_HPP
