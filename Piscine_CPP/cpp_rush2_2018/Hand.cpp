/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/

#include <iostream>
#include "Hand.hpp"

bool Hand::takeObject(Object *object)
{
	if (!_taken) {
		object->setTaken(true);
		_taken = object;
		std::cout << "The elf take the object." << std::endl;
	}
	std::cout << "The elf have already an object." << std::endl;
	return false;
}

bool Hand::takeObject(Warp *warp)
{
	if (!_taken) {
		warp->setTaken(true);
		_taken = warp;
		std::cout << "Whistles while working" << std::endl;
	}
	std::cout << "The elf have already an object." << std::endl;
	return false;
}

Object *Hand::getTaken() const
{
	return _taken;
}

void Hand::removeObject()
{
	_taken = NULL;
}

