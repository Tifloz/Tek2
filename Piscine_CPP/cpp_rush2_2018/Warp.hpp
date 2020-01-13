/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef RUSH2_WARP_HPP
#define RUSH2_WARP_HPP

#include "Object.hpp"

class Warp : public Object {
	protected:
		bool _isOpen;
		Object *_object;
	public:
		Warp(std::string title = "Warp");
		Object *getObject() const;
		virtual bool warpMeThat(Object *);
		bool openMe();
		bool closeMe();

};

#endif //RUSH2_WARP_HPP
