/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#ifndef DAY_ONE_CPP_LITTLEPONY_HPP
#define DAY_ONE_CPP_LITTLEPONY_HPP

#include "Toy.hpp"

class LittlePony : public Toy
{
    public:
    explicit LittlePony(std::string title = "happy pony");
    bool isTaken() const override;
};


#endif //DAY_ONE_CPP_LITTLEPONY_HPP
