/*
** EPITECH PROJECT, 2019
** cpp_rush03_2018
** File description:
**
*/
#include "SystemCore.hpp"

SystemCore::SystemCore()
{
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();
}

SystemCore::~SystemCore() = default;

bool SystemCore::updateData()
{

    return false;
}
