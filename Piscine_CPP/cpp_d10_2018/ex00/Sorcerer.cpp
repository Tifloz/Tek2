/*
** EPITECH PROJECT, 2022
** cpp_d10_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "Victim.hpp"
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ", " << this->_title << ", is born!"
        << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title
        << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
    return (this->_name);
}

std::string Sorcerer::getTitle() const
{
    return (this->_title);
}

void Sorcerer::polymorph(const Victim &slave) const
{
    slave.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, Sorcerer const &mage)
{
    return (os << "I am " << mage.getName() << ", " << mage.getTitle()
        << ", and I like ponies!" << std::endl);
}
