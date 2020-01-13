/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/
#include <iostream>
#include "Teddy.hpp"

Teddy::Teddy(std::string title) : Toy(title)
{
}

bool Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
    return Object::isTaken();
}

