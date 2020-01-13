/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_DATEMODULE_HPP
#define CPP_RUSH3_2018_DATEMODULE_HPP

#include "baseModule.hpp"

class dateModule : public baseModule {
	public:
		virtual ~dateModule();
		explicit dateModule(bool _isEnabled = true);
		bool update() override ;
		const std::string &getDate() const;
		const std::string &getTime() const;
		const std::string &getUptime() const;

	protected:
		std::string _date;
		std::string _time;
		std::string _uptime;
};

#endif //CPP_RUSH3_2018_DATEMODULE_HPP
