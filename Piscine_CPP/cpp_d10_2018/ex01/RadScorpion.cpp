/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}
