/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <fstream>
#include <cstring>
#include <iostream>
#include "systemModule.hpp"

systemModule::systemModule(bool _isEnabled) : baseModule("System", _isEnabled),
	_systemName("Unknown"), _kernelVersion("Unknown")
{
}

bool systemModule::update()
{
	if (!_isEnabled)
		return false;

	std::string temp;
	std::string toCompare;
	std::ifstream fileSystemName("/etc/os-release");
	std::ifstream fileKernelLinux("/proc/version");

	if (fileSystemName.is_open()) {
		std::getline(fileSystemName, temp);
		toCompare = std::strtok((char *)temp.c_str(), "=");
		while (!temp.empty() && !toCompare.empty() && toCompare != std::string("PRETTY_NAME")) {
			std::getline(fileSystemName, temp);
			if (!temp.empty())
				toCompare = std::strtok((char *)temp.c_str(), "=");
		}
		if (toCompare == std::string("PRETTY_NAME")) {
			temp = std::strtok(nullptr, "=");
			_systemName.assign(temp);
		} else
			_systemName.assign("Unknown");
		fileSystemName.close();
	} else
		_systemName.assign("Unknown");

	if (fileKernelLinux.is_open()) {
		std::getline(fileKernelLinux, temp);
		if (!temp.empty()) {
			std::strtok((char *)temp.c_str(), " ");
			std::strtok(nullptr, " ");
			_kernelVersion.assign(std::strtok(nullptr, " "));
			fileKernelLinux.close();
		}
	} else
		_kernelVersion.assign("Unknown");
	return true;
}

const std::string &systemModule::getSystemName() const
{
	return _systemName;
}

const std::string &systemModule::getKernelVersion() const
{
	return _kernelVersion;
}