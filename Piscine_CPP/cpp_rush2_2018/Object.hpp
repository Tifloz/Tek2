/*
** EPITECH PROJECT, 2022
** cpp_rush2_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_RUSH2_2018_OBJECT_HPP
#define CPP_RUSH2_2018_OBJECT_HPP
#include <iostream>

class Object
{
	protected:
	    const std::string _title;
		bool _taken;
		bool _isWarp;

	public:
		bool isWarp() const;
		explicit Object(std::string title);
		virtual ~Object();
		virtual bool isTaken() const;
		virtual void setTaken(bool status);
		virtual std::string getClassName();
	    const std::string &getTitle() const;
};
#endif //CPP_RUSH2_2018_OBJECT_HPP
