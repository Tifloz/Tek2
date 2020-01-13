/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include "Buzz.hpp"

Buzz::Buzz(std::string const &name, const std::string &filename) : Toy(BUZZ,
    name, filename)
{
}

Buzz::~Buzz() = default;