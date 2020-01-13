/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include "cpuModule.hpp"

cpuModule::cpuModule(bool isEnable) : baseModule("CPU", isEnable)
{
	std::ifstream file("/proc/cpuinfo");
	std::string temp("");
	std::string temp1("");
	std::string temp2("");

	if (file.is_open()) {

		std::getline(file, temp1);
		while (!temp1.empty() && temp1.find("vendor_id"))
			std::getline(file, temp1);
		std::strtok((char *)temp1.c_str(), ":");
		_info._vendor = std::strtok(nullptr, ":");

		std::getline(file, temp);
		while (!temp.empty() && temp.find("model name"))
			std::getline(file, temp);
		std::strtok((char *)temp.c_str(), ":");
		_info._modelName = std::strtok(nullptr, ":");

		file.close();
		update();
	}
}

cpuModule::~cpuModule()
{
}

static usageCPU getUsage(const std::string line, usageCPU &prev,
	std::string freq
)
{
	usageCPU cpu;
	std::string tmp("");
	std::ostringstream result;

	tmp = std::strtok((char *)line.c_str(), " ");
	if (!tmp.find("cpu")) {
		cpu._frequency = freq;
		cpu._user = std::atoi(std::strtok(nullptr, " "));
		cpu._nice = std::atoi(std::strtok(nullptr, " "));
		cpu._system = std::atoi(std::strtok(nullptr, " "));
		cpu._idle = std::atoi(std::strtok(nullptr, " "));
		cpu._iowait = std::atoi(std::strtok(nullptr, " "));
		cpu._irq = std::atoi(std::strtok(nullptr, " "));
		cpu._softiro = std::atoi(std::strtok(nullptr, " "));
		cpu._steal = std::atoi(std::strtok(nullptr, " "));

		int total =
			cpu._user + cpu._nice + cpu._system + cpu._irq + cpu._softiro +
				cpu._steal + cpu._idle + cpu._iowait;
		int prevTotal =
			prev._user + prev._nice + prev._system + prev._irq + prev._softiro +
				prev._steal + prev._idle + prev._iowait;

		int idled = cpu._idle - prev._idle;
		int totald = total - prevTotal;
		int totalUsage = (1000 * (totald - idled) / totald + 5) / 10;

		result << totalUsage;
		cpu._totalUsage = result.str();
	}
	return cpu;
}

static std::string retrieveFreq(std::string toClean)
{
	std::strtok((char *)toClean.c_str(), ":");
	return std::strtok(nullptr, ":");
}

static std::list<std::string> getFreq()
{
	std::ifstream file("/proc/cpuinfo");
	std::string temp;
	std::list<std::string> list;

	std::getline(file, temp);
	while (!temp.empty()) {
		if (!temp.find("cpu MHz"))
			list.push_back(retrieveFreq(temp));
		std::getline(file, temp);
		if (temp.empty())
			std::getline(file, temp);
	}
	//std::strtok((char *)temp.c_str(), ":");
	//_info._frequency = std::strtok(nullptr, ":");

	file.close();
	return list;
}

bool cpuModule::update()
{
	if (!_isEnabled)
		return false;

	std::ostringstream toConvert;
	usageCPU core;
	std::list<usageCPU> allCore;
	std::string temp("");
	std::ifstream file("/proc/stat");
	std::list<usageCPU>::iterator it = _info._usageCore.begin();
	std::list<std::string> list = getFreq();
	std::list<std::string>::iterator itFreq = list.begin();

	std::getline(file, temp);
	_info._usage = getUsage(temp, _info._usage, "Unknown");

	std::getline(file, temp);
	do {
		core = getUsage(temp, *it, *itFreq);
		allCore.push_back(core);
		std::advance(itFreq, 1);
		std::advance(it, 1);

		std::getline(file, temp);
	} while (!temp.find("cpu"));

	_info._usageCore = allCore;
	file.close();
	toConvert << allCore.size();
	_info._nbrCore = toConvert.str();
	return true;
}

const infoCPU &cpuModule::getInfo() const
{
	return _info;
}

infoCPU::infoCPU() : _modelName("Unknown"), _nbrCore("Unknown")
{
}

usageCPU infoCPU::getCore() const
{
    auto it = _usageCore.begin();
	static int pos = 0;

	if (pos >= std::atoi((char *)_nbrCore.c_str()))
		pos = 0;
	std::advance(it, pos);
	pos++;
	return *it;
}

usageCPU::usageCPU() : _user(0), _nice(0), _system(0), _idle(0), _iowait(0),
	_irq(0), _softiro(0), _steal(0), _totalUsage(""), _frequency("Unknown")
{
}
