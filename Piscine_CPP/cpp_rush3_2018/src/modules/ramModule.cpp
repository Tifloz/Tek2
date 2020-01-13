/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include "ramModule.hpp"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sstream>
#include <cmath>

ramModule::ramModule(bool isEnable)  : baseModule("RAM", isEnable), _total(""), _used("")
{
}

bool ramModule::update()
{
	if (!_isEnabled)
		return false;

	std::ostringstream toConvert;
	std::ostringstream toConvertUsed;

	struct sysinfo memInfo;
	sysinfo (&memInfo);

	float memory = (memInfo.totalram * memInfo.mem_unit)/1024;
	memory = round(memory /10000) / 100;
	toConvert << (memory);
	_total = toConvert.str();

	float usedMemory = (memInfo.totalram - memInfo.freeram) * memInfo.mem_unit / 1024;
	usedMemory = round(usedMemory / 10000) / 100;
	toConvertUsed << (usedMemory);
	_used = toConvertUsed.str();
	return true;
}

const std::string &ramModule::getTotal() const
{
	return _total;
}

const std::string &ramModule::getUsed() const
{
	return _used;
}
