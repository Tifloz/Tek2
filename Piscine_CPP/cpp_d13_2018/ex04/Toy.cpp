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

Toy &Toy::operator=(const Toy &toy)
{
    this->_type = toy._type;
    this->_name = toy._name;
    this->_picture = toy._picture;
    return *this;
}

Toy::Toy(const Toy &copy) : _type(copy._type), _name(copy._name),
    _picture(copy._picture)
{
}

void Toy::speak(const std::string &message)
{
    std::cout << this->_name << " \"" << message << "\"" << std::endl;
}

Toy &Toy::operator<<(std::string const &message)
{
    this->_picture.data = message;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Toy const &obj)
{
    return (os << obj.getName() << std::endl << obj.getAscii() << std::endl);
}