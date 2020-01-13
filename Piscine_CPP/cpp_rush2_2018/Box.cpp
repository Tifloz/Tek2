/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/

#include <iostream>
#include "Box.hpp"

bool Box::warpMeThat(Object *object)
{
	if (_isOpen)
		return Warp::warpMeThat(object);
	std::cout << "The box is closed." << std::endl;
	return false;
}

Box::Box(std::string title) :  Warp(title)
{
}


