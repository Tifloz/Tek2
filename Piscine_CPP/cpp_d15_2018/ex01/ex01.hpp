/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D15_2018_ET01_HPP
#define CPP_D15_2018_ET01_HPP

#include <cstring>

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return 0;
    else if (a < b)
        return -1;
    else
        return 1;
}

template<>
int compare<const char *>(const char *const &a, const char *const &b)
{
    if (strcmp(a, b) == 0)
        return 0;
    else if (strcmp(a, b) < 0)
        return -1;
    else
        return 1;
}

#endif //CPP_D15_2018_ET01_HPP
