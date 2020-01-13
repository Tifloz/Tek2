/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/
#include <iostream>
#include "IElf.hpp"

bool IElf::warp(Object *object)
{
	Warp *warp = nullptr;
	if (!object) {
		std::cout << "There is no object to warp." << std::endl;
		return false;
	}
	if (hand.getTaken() && !hand.getTaken()->isWarp()) {
		warp = (Warp *)hand.getTaken();
		return warp->warpMeThat(object);
	}
	std::cout << "It's not a warp." << std::endl;
	return false;
}

IElf::IElf()
{
	_convoyerBelt = new(PapaXmasConveyorBelt);
	_table = new(PapaXmasTable);
}

std::string *IElf::look()
{
	std::string *list = {};
	Object **array = _table->GetArray();

	if (_table) {
		for (int offset = 0; _table; offset++)
			list[offset] = array[offset]->getTitle();
	}
	return list;
}

bool IElf::putObjectOnTable()
{
	if (!hand.getTaken()) {
		std::cout << "There are no object in elf's hands" << std::endl;
		return false;
	}
	if (_table->GetSpace() > 10) {
		std::cout << "There is no place in the table" << std::endl;
		return false;
	}
	_table->AddObject(hand.getTaken());
	hand.removeObject();
	std::cout << "Move object in the table" << std::endl;
	return true;
}

bool IElf::pickObjectOnTable(int offset)
{
	if (hand.getTaken()) {
		std::cout << "There is object in elf's hands" << std::endl;
		return false;
	}
	if (!_table->GetSpace() == 0) {
		std::cout << "There is nothing in the table" << std::endl;
		return false;
	}
	if (!_table->GetObject(offset)) {
		std::cout << "Object " << std::endl;
		return false;
	}
	hand.takeObject(_table->GetObject(offset));
	_table->DeleteObject(offset);
	std::cout << "Move object in the table" << std::endl;
	return true;
}
