/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D15_2018_ET00_HPP
#define CPP_D15_2018_ET00_HPP

template<typename T>

void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
const T &min(const T &a, const T &b)
{
    if (a <= b)
        return a;
    return b;
}

template<typename T>
const T &max(const T &a, const T &b)
{
    if (a >= b)
        return a;
    return b;
}

template<typename T>
T add(const T &a, const T &b)
{
    return a + b;
}

#endif //CPP_D15_2018_ET00_HPP
