/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_201YAMS_2018_TOOLS_HPP
#define INC_201YAMS_2018_TOOLS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

void parseInput(int ac, char **av);

void printUsage(char **av);

void checkError(std::vector<std::string> v);

#endif //INC_201YAMS_2018_TOOLS_HPP
