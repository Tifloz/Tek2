/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <string>
#include <fstream>
#include "userModule.hpp"
#include "../ncurses/User.hpp"

userModule::~userModule() = default;

bool userModule::update()
{
	if (!_isEnabled)
		return false;

	std::ifstream file("/etc/hostname");

	if(file.is_open()) {
		std::getline(file, _hostname);
		file.close();
	} else
		_hostname.assign("Unknown");
	_username.assign(std::getenv("USER"));
	return true;
}

userModule::userModule(bool enable) : baseModule("User", enable), _username("Unknown"), _hostname("Unknown")
{
}

const std::string &userModule::getUsername() const
{
    return _username;
}

const std::string &userModule::getHostname() const
{
    return _hostname;
}


