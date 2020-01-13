/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D15_2018_ET02_HPP
#define CPP_D15_2018_ET02_HPP

#include <iostream>

template<typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return a;
    return b;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return a;
    return b;
}

template<typename T>
const T &templateMin(const T *array, int size)
{
    T &mini = const_cast<T &>(array[0]);

    for (int i = 1; i < size; i++) {
        mini = min<T>(mini, array[i]);
    }
    return mini;
}

int nonTemplateMin(int *array, int size)
{
    int mini = array[0];

    for (int i = 1; i < size; i++) {
        mini = min(mini, array[i]);
    }
    return mini;
}

#endif //CPP_D15_2018_ET02_HPP
