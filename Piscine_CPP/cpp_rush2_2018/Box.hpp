/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef RUSH2_BOX_HPP
#define RUSH2_BOX_HPP

#include "Warp.hpp"

class Box : public Warp {
	public:
		Box(std::string title = "Box");
		bool warpMeThat(Object *) final;

};

#endif //RUSH2_BOX_HPP
