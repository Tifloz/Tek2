/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include "baseModule.hpp"

bool baseModule::onScreen(bool state)
{
	_isEnabled = state;
	return state;
}

bool baseModule::isEnable()
{
	return _isEnabled;
}

bool baseModule::update()
{
	return false;
}

std::string baseModule::getName()
{
	return _name;
}

baseModule::baseModule(const std::string &_name, bool _isEnabled) : _name(_name), _isEnabled(_isEnabled)
{
}

