/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_RAMMODULE_HPP
#define CPP_RUSH3_2018_RAMMODULE_HPP

#include "baseModule.hpp"

class ramModule : public baseModule {
	public:
		ramModule(bool isEnable = true);
		bool update() override;
		const std::string &getTotal() const;
		const std::string &getUsed() const;

	protected:
		std::string _total;
		std::string _used;
};

#endif //CPP_RUSH3_2018_RAMMODULE_HPP
