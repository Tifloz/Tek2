/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/
#include <iostream>
#include "LittlePony.hpp"

LittlePony::LittlePony(std::string title) : Toy(title)
{
}

bool LittlePony::isTaken() const
{
    std::cout << "yo man";
    return Object::isTaken();
}

