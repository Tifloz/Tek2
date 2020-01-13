/*
** EPITECH PROJECT, 2022
** cpp_d15_2018
** File description:
** Created by Florian Louvet,
*/
#include "ex03.hpp"

int main()
{
    int tab[] = {11, 3, 89, 42};
    foreach(tab, print<int>, 4);
    std::string tab2[] = {"j'", "aime", "les", "templates", "!"};
    foreach(tab2, print, 5);
    return 0;
}