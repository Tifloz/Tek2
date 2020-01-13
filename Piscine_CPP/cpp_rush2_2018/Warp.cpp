/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/
#include <iostream>
#include "Warp.hpp"

Warp::Warp(std::string title) : Object(title),_isOpen(false), _object(nullptr)
{
}

bool Warp::warpMeThat(Object *object)
{
	if (!_object) {
		_object = object;
		_isOpen = false;
		std::cout << "The object is in the warp." << std::endl;
		return true;
	}
	std::cout << "There is already an object in the wrap." << std::endl;
	return false;
}

bool Warp::openMe()
{
	if (!_isOpen) {
		_isOpen = true;
		std::cout << "The box is now open." << std::endl;
		return true;
	}
	std::cout << "The box is already open." << std::endl;
	return false;
}

bool Warp::closeMe()
{
	if (_isOpen) {
		_isOpen = false;
		std::cout << "The box is now closed." << std::endl;
		return true;
	}
	std::cout << "The box is already closed." << std::endl;
	return false;
}

Object *Warp::getObject() const
{
	if (_isOpen)
		return _object;
	std::cout << "We need to open the warps" << std::endl;
	return (NULL);
}
