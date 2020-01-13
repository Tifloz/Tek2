/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "Peon.hpp"
Peon::Peon(std::string name) : Victim(name)
{
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a pink pony!"
        << std::endl;
}
