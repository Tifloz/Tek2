/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3)
{
}

Lemon::~Lemon() = default;

std::string const &Lemon::getName() const
{
    return this->_name;
}
