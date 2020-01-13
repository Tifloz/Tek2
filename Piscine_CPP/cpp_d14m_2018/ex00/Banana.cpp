/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#include "Banana.hpp"

Banana::Banana() : Fruit("banana", 5)
{
}

Banana::~Banana() = default;

std::string const &Banana::getName() const
{
    return this->_name;
}
