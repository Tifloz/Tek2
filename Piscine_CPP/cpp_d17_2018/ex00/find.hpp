/*
** EPITECH PROJECT, 2022
** cpp_d17_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D17_2018_FIND_HPP
#define CPP_D17_2018_FIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &file, int index)
{
    return std::find(file.begin(), file.end(), index);
}

#endif //CPP_D17_2018_FIND_HPP
