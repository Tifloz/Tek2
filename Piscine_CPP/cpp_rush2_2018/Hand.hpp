/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef RUSH2_HAND_HPP
#define RUSH2_HAND_HPP

#include "Object.hpp"
#include "Warp.hpp"

class Hand {
	public:
		bool takeObject(Object *);
		bool takeObject(Warp *);
		void removeObject();
		Object *getTaken() const;

	protected:
		Object *_taken;
		bool _isWarp;
};

#endif //RUSH2_HAND_HPP
