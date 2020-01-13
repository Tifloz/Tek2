/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string name)
{
    this->_name = name;
    std::cout << "Some random victim called " << this->_name << " just popped!"
        << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name
        << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName() const
{
    return this->_name;
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!"
        << std::endl;
}

std::ostream &operator<<(std::ostream &os, Victim const &slave)
{
    return (os << "I'm " << slave.getName() << " and i like otters!"
        << std::endl);
}
