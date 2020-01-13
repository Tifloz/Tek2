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

void Buzz::speak(std::string const &message)
{
    std::cout << "BUZZ: " << this->_name << " \"" << message << "\""
        << std::endl;
}

bool Buzz::speak_es(const std::string &message)
{
    std::cout << "BUZZ: " << this->_name << " senorita \"" << message
        << "\" senorita" << std::endl;
    return true;
}

Buzz::~Buzz() = default;