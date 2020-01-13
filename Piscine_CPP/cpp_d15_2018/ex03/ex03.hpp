/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D15_2018_ET03_HPP
#define CPP_D15_2018_ET03_HPP

#include <iostream>

template<typename T>
void foreach(const T *array, void (func)(const T &), int size)
{
    for (int i = 0; i < size; i++) {
        func(array[i]);
    }
}

template<typename T>
void print(const T &val)
{
    std::cout << val << '\n';
}

#endif //CPP_D15_2018_ET03_HPP
