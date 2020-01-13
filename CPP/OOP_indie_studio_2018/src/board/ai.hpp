/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** ai.hpp
*/

#ifndef INDIE_STUDIO_AI_HPP
#define INDIE_STUDIO_AI_HPP

#include "Player.hpp"

class Ai: public Player {
	public:
	enum difficulty{
		EASY,
		MEDIUM,
		HARD,
	};
	enum type{
		STANDARD,
	};
	Ai(int id, irr::IrrlichtDevice *device, const irr::io::path &path,
	       const irr::core::vector3df &pos, difficulty diff, type type,
	       irr::scene::IMetaTriangleSelector *meta, AudioManager *AudioManager, Map &map
	);
	void run(std::vector<Bomb *> &Bomb, bool run);
	protected:
		difficulty _difficulty;
		type _type;
		Map _map;
		std::pair<int, int>_MyPosition;
		void setPosition();
		bool isDangerousCase(int x, int y, std::vector<Bomb *> &Bomb);
		bool isCaseBomb(int x, int y, std::vector<Bomb *> &Bomb);
		std::pair<int, int>_Goal;
		void setGoal();
};

#endif //INDIE_STUDIO_AI_HPP
