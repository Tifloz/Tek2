#include <utility>

/*
** EPITECH PROJECT, 2022
** cpp_rush2_2018
** File description:
** Created by Florian Louvet,
*/
#include "Object.hpp"

Object::Object(std::string title) : _title(std::move(title)) , _taken(false), _isWarp(false)
{

}

Object::~Object() = default;

bool Object::isTaken() const
{
    return _taken;
}

void Object::setTaken(bool status)
{
    this->_taken = status;
}

const std::string &Object::getTitle() const
{
    return _title;
}

std::string Object::getClassName()
{
    int i = 1;
    std::string temp = typeid(*this).name();

    while (temp[0] <= '9' && temp[0] >= '0') {
        temp = typeid(*this).name() + i;
        i++;
    }
    return temp;
}

bool Object::isWarp() const
{
	return _isWarp;
}
