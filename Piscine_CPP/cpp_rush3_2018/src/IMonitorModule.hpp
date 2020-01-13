/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_IMONITORMODULE_HPP
#define CPP_RUSH3_2018_IMONITORMODULE_HPP

#include <string>

class IMonitorModule {
	public:
		virtual bool onScreen(bool state) = 0;
		virtual bool isEnable() = 0;
		virtual bool update() = 0;
		virtual std::string getName() = 0;
};

#endif //CPP_RUSH3_2018_IMONITORMODULE_HPP
