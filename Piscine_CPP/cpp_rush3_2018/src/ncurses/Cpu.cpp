/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#include "Cpu.hpp"

Cpu::Cpu() = default;

Cpu::~Cpu()= default;


void Cpu::DisplayCpu()
{
    auto it = _info._usageCore.begin();
	int numCore = 0;

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	attron(A_UNDERLINE);
	mvwprintw(stdscr, 14, 1, "CPU");
	attroff(COLOR_PAIR(3));
	attroff(A_UNDERLINE);
	attron(COLOR_PAIR(2));
	while (it != _info._usageCore.end()) {
		mvwprintw(stdscr, 15 + numCore, 3, "Core %d %s%%", numCore, it->_totalUsage.c_str());
		for (int i = 0; i < atoi(it->_totalUsage.c_str()); i++)
			mvwprintw(stdscr, 15 + numCore, 14 + i, "|");
		mvwprintw(stdscr, 15 + numCore, 110 , "%s MHz", it->_frequency.c_str());
		std::advance(it, 1);
		numCore++;
	}
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(1));

	attroff(COLOR_PAIR(1));
}
