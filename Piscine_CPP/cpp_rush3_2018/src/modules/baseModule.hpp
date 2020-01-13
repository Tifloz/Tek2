/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_BASEMODULE_HPP
#define CPP_RUSH3_2018_BASEMODULE_HPP

#include "../IMonitorModule.hpp"

class baseModule : public IMonitorModule {
	public:
		baseModule(const std::string &_name, bool _isEnabled);
		bool onScreen(bool state) override;
		bool isEnable() override;
		bool update() override;
		std::string getName() override;
	protected:
		const std::string _name;
		bool _isEnabled;
};

#endif //CPP_RUSH3_2018_BASEMODULE_HPP
