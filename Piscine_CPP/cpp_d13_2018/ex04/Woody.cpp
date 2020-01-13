/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include "Woody.hpp"

Woody::Woody(std::string const &name, const std::string &filename) : Toy(WOODY,
    name, filename)
{
}

void Woody::speak(std::string const &message)
{
    std::cout << "WOODY: " << this->_name << " \"" << message << "\""
        << std::endl;
}

Woody::~Woody() = default;
