/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
    this->_picture.data = "";
}

Toy::Toy(Toy::ToyType type, std::string const &name, const std::string &picture)
    : _type(type), _name(name), _picture(picture)
{
}

Toy::~Toy() = default;

int Toy::getType() const
{
    return this->_type;
}

std::string const &Toy::getName() const
{
    return this->_name;
}

std::string const &Toy::getAscii() const
{
    return this->_picture.data;
}

void Toy::setName(std::string const &name)
{
    this->_name = name;
}

void Toy::setAscii(std::string const &picture)
{
    this->_picture.getPictureFromFile(picture);
}
