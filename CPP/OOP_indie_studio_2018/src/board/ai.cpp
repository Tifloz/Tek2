/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** ai.cpp
*/

#include "ai.hpp"

Ai::Ai(int id, irr::IrrlichtDevice *device, const irr::io::path &path,
	       const irr::core::vector3df &pos, difficulty diff, type typeMode,
	       irr::scene::IMetaTriangleSelector *meta, AudioManager *AudioManager, Map &map
) : Player(id, device, path, pos, false, meta, AudioManager), _difficulty(diff), _type(typeMode), _map(map)
{
	setPosition();
	_Goal = _MyPosition;
}

void Ai::run(std::vector<Bomb *> &Bomb, bool run)
{
	short inWall = random() % 4;
	auto lastPos = _MyPosition;
	int posBomb = random() % 500;


	if (!run ) {
		return;
	}
	setPosition();
	setAction("left", false);
	setAction("right", false);
	setAction("down", false);
	setAction("up", false);
	setAction("bomb", false);

	if (_Goal == _MyPosition) {
		setGoal();
	}
	if (isCaseBomb(_MyPosition.first, _MyPosition.second, Bomb) ||isCaseBomb(_MyPosition.first -1 , _MyPosition.second, Bomb)|| isCaseBomb(_MyPosition.first + 1, _MyPosition.second, Bomb) || isCaseBomb(_MyPosition.first, _MyPosition.second -1 , Bomb) || isCaseBomb(_MyPosition.first, _MyPosition.second +1, Bomb) ) {
		if (!isCaseBomb(_MyPosition.first - 1, _MyPosition.second,
				Bomb) &&
		    _map.cellIsFree(_MyPosition.first - 1, _MyPosition.second))
			setAction("left", true);
		else if (!isCaseBomb(_MyPosition.first + 1, _MyPosition.second,
				     Bomb) &&
			 _map.cellIsFree(_MyPosition.first + 1,
					 _MyPosition.second))
			setAction("right", true);
		else if (!isCaseBomb(_MyPosition.first, _MyPosition.second - 1,
				     Bomb) && _map.cellIsFree(_MyPosition.first,
							      _MyPosition.second -
							      1))
			setAction("down", true);
		else if (!isCaseBomb(_MyPosition.first, _MyPosition.second + 1,
				     Bomb) && _map.cellIsFree(_MyPosition.first,
							      _MyPosition.second +
							      1))
			setAction("up", true);
	}else if (_MyPosition.first > _Goal.first && _map.cellIsFree(_MyPosition.first - 1, _MyPosition.second))
		setAction("left", true);
	else if (_MyPosition.first < _Goal.first && _map.cellIsFree(_MyPosition.first + 1, _MyPosition.second))
		setAction("right", true);
	else if (_MyPosition.second > _Goal.second  && _map.cellIsFree(_MyPosition.first, _MyPosition.second - 1))
		setAction("down", true);
	else if (_MyPosition.second < _Goal.second && _map.cellIsFree(_MyPosition.first, _MyPosition.second + 1))
		setAction("up", true);
	else {
		setAction("left", false);
		setAction("right", false);
		setAction("down", false);
		setAction("up", false);
		setAction("bomb", false);
		if (inWall == 0)
			setAction("left", true);
		else if (inWall == 1)
			setAction("right", true);
		else if (inWall == 2)
			setAction("down", true);
		else if (inWall == 3)
			setAction("up", true);
	}

	if (!_map.cellIsFree(_MyPosition.first, _MyPosition.second) || lastPos == _MyPosition) {
		setAction("left", false);
		setAction("right", false);
		setAction("down", false);
		setAction("up", false);
		setAction("bomb", false);
		if (inWall == 0)
			setAction("left", true);
		else if (inWall == 1)
			setAction("right", true);
		else if (inWall == 2)
			setAction("down", true);
		else if (inWall == 3)
			setAction("up", true);
	}
	if (posBomb == 0) {
		setAction("bomb", true);
	}

}

/*
void Ai::run(std::vector<Bomb *> &Bomb, bool run)
{
	short shouldBomb = random() % 100;


	if (!run) {
		return;
	}
	setPosition();
	setAction("left", false);
	setAction("right", false);
	setAction("down", false);
	setAction("up", false);
	setAction("bomb", false);
	if (_Goal == _MyPosition) {
		setGoal();
	} else if (isCaseBomb(_MyPosition.first, _MyPosition.second, Bomb)) {
		if (!isCaseBomb(_MyPosition.first - 1, _MyPosition.second, Bomb) && _map.cellIsFree(_MyPosition.first - 1, _MyPosition.second))
			setAction("left", true);
		else if (!isCaseBomb(_MyPosition.first + 1, _MyPosition.second, Bomb) && _map.cellIsFree(_MyPosition.first + 1, _MyPosition.second))
			setAction("right", true);
		else if (!isCaseBomb(_MyPosition.first, _MyPosition.second - 1, Bomb ) && _map.cellIsFree(_MyPosition.first, _MyPosition.second - 1))
			setAction("down", true);
		else if (!isCaseBomb(_MyPosition.first, _MyPosition.second + 1, Bomb) && _map.cellIsFree(_MyPosition.first, _MyPosition.second + 1))
			setAction("up", true);
		else
			std::cerr << "y'a pas de solution wtf" << std::endl;
	} else if (_MyPosition.first > _Goal.first && _map.cellIsFree(_MyPosition.first - 1, _MyPosition.second)&& _map.cellIsFree(_MyPosition.first, _MyPosition.second))
		setAction("left", true);
	else if (_MyPosition.first < _Goal.first && _map.cellIsFree(_MyPosition.first + 1, _MyPosition.second)&& _map.cellIsFree(_MyPosition.first, _MyPosition.second))
		setAction("right", true);
	else if (_MyPosition.second > _Goal.second  && _map.cellIsFree(_MyPosition.first, _MyPosition.second - 1)&& _map.cellIsFree(_MyPosition.first, _MyPosition.second))
		setAction("down", true);
	else if (_MyPosition.second < _Goal.second && _map.cellIsFree(_MyPosition.first, _MyPosition.second + 1)&& _map.cellIsFree(_MyPosition.first, _MyPosition.second))
		setAction("up", true);
	else {
		setAction("bomb", true);
	}
}
*/

void Ai::setPosition()
{
	const irr::core::vector3df Position = _mesh->getPosition();

	_MyPosition = std::make_pair<int, int>(static_cast<int>(Position.X / 10),
					       static_cast<int>(Position.Y / 10));
}

bool Ai::isDangerousCase(int xPos, int yPos, std::vector<Bomb *> &Bomb)
{
	for (int x = -1; x <= 1; ++x) {

		if (isCaseBomb(x + xPos, yPos, Bomb)) {
			return (true);
		}
	}

	for (int y = -1; y <= 1; ++y) {
		if (isCaseBomb(xPos, y + yPos, Bomb))
			return (true);
	}
	return false;
}

bool Ai::isCaseBomb(int x, int y, std::vector<Bomb *> &Bomb)
{
	irr::core::vector3df BombPosition;
	std::pair<int, int>RealPos;


	for (auto bombs : Bomb) {
		BombPosition = bombs->getMesh()->getPosition();
		RealPos = std::make_pair<int, int>(static_cast<int>(BombPosition.X / 10),
						       static_cast<int>(BombPosition.Y / 10));
		if (RealPos.first == x && RealPos.second == y) {

			return (true);
		}
	}
	return false;
}

void Ai::setGoal()
{
	short goalX = random() % 11;
	short goalY = random() % 11;

	_Goal =  std::make_pair<int, int>(static_cast<int>(goalX),
						  static_cast<int>(goalY));
}


