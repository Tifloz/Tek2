/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_RAM_HPP
#define CPP_RUSH3_2018_RAM_HPP

#include "../modules/ramModule.hpp"
#include "SystemCore.hpp"

class Ram : public ramModule, public SystemCore {
	public:
	Ram();
	~Ram();
	void DisplayRam();
};


#endif //CPP_RUSH3_2018_RAM_HPP
