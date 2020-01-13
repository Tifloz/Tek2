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

bool Toy::setAscii(std::string const &picture)
{
    if (!this->_picture.getPictureFromFile(picture)) {
        this->error.setType(Error::PICTURE);
        return false;
    }
    return true;
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

bool Toy::speak_es(std::string const &message)
{
    (void)message;
    this->error.setType(Error::SPEAK);
    return false;
}

Toy::Error const &Toy::getLastError() const
{
    return this->error;
}

std::ostream &operator<<(std::ostream &os, Toy const &obj)
{
    return (os << obj.getName() << std::endl << obj.getAscii() << std::endl);
}

Toy::Error::Error() : type(UNKNOWN)
{
}

std::string Toy::Error::what() const
{
    if (this->type == PICTURE)
        return "bad new illustration";
    else if (this->type == SPEAK)
        return "wrong mode";
    else
        return "";
}

std::string Toy::Error::where() const
{
    if (this->type == PICTURE)
        return "setAscii";
    else if (this->type == SPEAK)
        return "speak_es";
    else
        return "";
}

void Toy::Error::setType(Toy::Error::ErrorType type)
{
    this->type = type;
}
