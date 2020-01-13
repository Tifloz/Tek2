/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#ifndef DAY_ONE_CPP_TEDDY_HPP
#define DAY_ONE_CPP_TEDDY_HPP

#include "Toy.hpp"

class Teddy : public Toy
{
    public:
        explicit Teddy(std::string title = "cuddles");
        bool isTaken() const override;
};

#endif //DAY_ONE_CPP_TEDDY_HPP
