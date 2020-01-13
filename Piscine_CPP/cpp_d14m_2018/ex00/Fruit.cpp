/*
** EPITECH PROJECT, 2022
** cpp_d14m_2018
** File description:
** Created by Florian Louvet,
*/
#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, int vitamins) : _name(name),
    _vitamins(vitamins)
{
}

Fruit::~Fruit() = default;

std::string const &Fruit::getName() const
{
    return this->_name;
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}

Fruit &Fruit::operator=(const Fruit &fruit)
{
    this->_name = fruit._name;
    this->_vitamins = fruit._vitamins;
    return *this;
}

bool Fruit::operator==(const Fruit &fruit)
{
    if (this->_name == fruit.getName() &&
        this->_vitamins == fruit.getVitamins())
        return true;
    return false;
}
