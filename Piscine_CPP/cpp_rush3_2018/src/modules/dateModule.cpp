/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "dateModule.hpp"

dateModule::~dateModule() = default;

dateModule::dateModule(bool _isEnabled) : baseModule("Date and Time", _isEnabled),
	_date("Unknown"), _time("Unknown"), _uptime("Unknown")
{
}

bool dateModule::update()
{
	if (!_isEnabled)
		return false;

	std::ostringstream convert;
	std::string temp("");
	std::time_t t = std::time(NULL);
	char mbstr[100];

	if (std::strftime(mbstr, 100, "%a %w %b %Y", std::localtime(&t)))
		_date.assign(mbstr);
	else
		_date.assign("Unknown");
	if (std::strftime(mbstr, 100, "%T", std::localtime(&t)))
		_time.assign(mbstr);
	else
		_time.assign("Unknown");

	std::ifstream("/proc/uptime", std::ios::in) >> temp;
	_uptime.assign("");

	int day = std::atof((char *)temp.c_str()) / 60 / 60 / 24;
	int hours = std::atof((char *)temp.c_str()) / 60 / 60;
	hours %= 24;
	int minutes = std::atof((char *)temp.c_str()) / 60;
	minutes %= 60;
	int seconds = std::atof((char *)temp.c_str());
	seconds %= 60;

	convert << day << " day(s) "
		<< std::setfill('0') << std::setw(2) << hours << ":"
		<< std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << seconds;
	_uptime.assign(convert.str());
	return true;
}


const std::string &dateModule::getDate() const
{
	return _date;
}

const std::string &dateModule::getTime() const
{
	return _time;
}

const std::string &dateModule::getUptime() const
{
	return _uptime;
}
