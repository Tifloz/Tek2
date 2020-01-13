/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_OSMODULE_HPP
#define CPP_RUSH3_2018_OSMODULE_HPP

#include "baseModule.hpp"

class systemModule : public baseModule {
	public:
		explicit systemModule(bool _isEnabled = true);
		bool update() override;
		const std::string &getSystemName() const;
		const std::string &getKernelVersion() const;

	protected:
		std::string _systemName;
		std::string _kernelVersion;

};

#endif //CPP_RUSH3_2018_OSMODULE_HPP
