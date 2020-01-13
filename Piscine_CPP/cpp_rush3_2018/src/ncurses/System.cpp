/*
** EPITECH PROJECT, 2019
** cpp_rush03_2018
** File description:
**
*/
#include "System.hpp"

System::System() = default;

System::~System() = default;;

void System::DisplaySystem()
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    attron(A_UNDERLINE);
    mvwprintw(stdscr, 10, 1, "System Information Module");
    attroff(COLOR_PAIR(3));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 11, 3, "System Name:");
    mvwprintw(stdscr, 12, 3, "Kernel Version:");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 11, 4 + 17, "%s", _systemName.c_str());
    mvwprintw(stdscr, 12, 4 + 17, "%s", _kernelVersion.c_str());
    attroff(COLOR_PAIR(1));
}
