/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include "Ram.hpp"

Ram::Ram() = default;

Ram::~Ram() = default;

void Ram::DisplayRam()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	attron(A_UNDERLINE);
	mvwprintw(stdscr, 20, 1, "RAM");
	attroff(COLOR_PAIR(3));
	attroff(A_UNDERLINE);
	attron(COLOR_PAIR(2));

	mvwprintw(stdscr, 20, 45, "%sGo/%sGo used", getUsed().c_str(), getTotal().c_str());

	if ( std::atoi(getTotal().c_str()) != 0) {
		float total = std::atof(getUsed().c_str()) / std::atof(getTotal().c_str());
		total *= 100;
		for (int i = 0; i < total; i++)
			mvwprintw(stdscr, 21, 10 + i, "|");
	}
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(1));

	attroff(COLOR_PAIR(1));
}
