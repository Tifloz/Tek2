/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#ifndef DAY_ONE_CPP_ELF_HPP
#define DAY_ONE_CPP_ELF_HPP

#include "Hand.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"

class IElf {
	public:
		bool warp(Object *);
		std::string *look();
		bool putObjectOnTable();
		bool pickObjectOnTable(int offset);
		IElf();
	private:
		PapaXmasConveyorBelt *_convoyerBelt;
		PapaXmasTable *_table;
		Hand hand;
};

#endif //DAY_ONE_CPP_ELF_HPP
