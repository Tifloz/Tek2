/*
** EPITECH PROJECT, 2019
** cpp_rush03_2018
** File description:
**
*/
#include "Date.hpp"

Date::Date() = default;

Date::~Date() = default;;

void Date::DisplayDateTime()
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    attron(A_UNDERLINE);
    mvwprintw(stdscr, 6, 1, "Date & Time Module");
    attroff(COLOR_PAIR(3));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 7, 3, "Date:");
    mvwprintw(stdscr, 8, 3, "Time:");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 7, 4 + 9, "%s", _date.c_str());
    mvwprintw(stdscr, 8, 4 + 9, "%s", _time.c_str());
    attroff(COLOR_PAIR(1));
}
