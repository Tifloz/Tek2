/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_MODULEUSER_HPP
#define CPP_RUSH3_2018_MODULEUSER_HPP

#include "baseModule.hpp"

class userModule : public baseModule {
	public:
		~userModule();
		explicit userModule(bool enable = true);
		bool update() override ;
		const std::string &getUsername() const;
		const std::string &getHostname() const;

	protected:
		std::string _username;
		std::string _hostname;

};
#endif //CPP_RUSH3_2018_MODULEUSER_HPP
