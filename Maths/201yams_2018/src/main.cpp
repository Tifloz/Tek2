/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include <string>
#include "../include/tools.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    if (ac > 7)
        printUsage(av);
    parseInput(ac, av);
    return (0);
}