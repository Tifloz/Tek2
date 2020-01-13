/*
** EPITECH PROJECT, 2019
** cpp_rush03_2018
** File description:
**
*/
#include <ncurses.h>
#include "User.hpp"

User::User() = default;

User::~User() = default;;

void User::DisplayUserHost()
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    attron(A_UNDERLINE);
    mvwprintw(stdscr, 2, 1, "Hostname & Username Module");
    attroff(COLOR_PAIR(3));
    attroff(A_UNDERLINE);
    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 3, 3, "Username:");
    mvwprintw(stdscr, 4, 3, "Hostname:");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 3, 4 + 9, "%s", _username.c_str());
    mvwprintw(stdscr, 4, 4 + 9, "%s", _hostname.c_str());
    attroff(COLOR_PAIR(1));
}
