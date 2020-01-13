/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_CPU_HPP
#define CPP_RUSH3_2018_CPU_HPP

#include "SystemCore.hpp"
#include "cpuModule.hpp"

class Cpu : public cpuModule, public SystemCore {
	public:
		Cpu();
		~Cpu() override;
		void DisplayCpu();
};

#endif //CPP_RUSH3_2018_CPU_HPP
