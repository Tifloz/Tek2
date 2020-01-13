/*
** EPITECH PROJECT, 2022
** 201yams_2018
** File description:
** Created by Florian Louvet,
*/
#include "../include/tools.hpp"
#include "../include/Pair.hpp"
#include "../include/Brelan.hpp"
#include "../include/Four.hpp"
#include "../include/Straight.hpp"
#include "../include/Full.hpp"
#include "../include/Yams.hpp"

void printUsage(char **av)
{
    std::string str;

    str = av[1];
    if (str == "-h") {
        std::cout << "USAGE" << std::endl << "	./201yams d1 d2 d3 d4 d5 c"
            << std::endl << std::endl << "DESCRIPTION" << std::endl
            << "	d1	value of the first die (0 if not thrown)" << std::endl
            << "	d2	value of the second die (0 if not thrown)"
            << std::endl << "	d3	value of the third die (0 if not thrown)"
            << std::endl << "	d4	value of the fourth die (0 if not thrown)"
            << std::endl << "	d5	value of the fifth die (0 if not thrown)"
            << std::endl << "	c	expected combination" << std::endl;
    } else {
        std::cerr << "Bad input : Use ./201yams -h for help" << std::endl;
        exit(84);
    }
}

void parseInput(int ac, char **av)
{
    std::vector<std::string> v;
    int i = 1;

    while (av[i] != nullptr) {
        v.emplace_back(av[i]);
        i++;
    }
    checkError(v);

    if (v[5].find("pair_") != std::string::npos) {
        Pair pair(v);
        pair.calc();
    } else if (v[5].find("three_") != std::string::npos) {
        Brelan brelan(v);
        brelan.calc();
    } else if (v[5].find("four_") != std::string::npos) {
        Four four(v);
        four.calc();
    } else if (v[5].find("full_") != std::string::npos) {
        Full full(v);
        full.calc();
    } else if (v[5].find("straight_") != std::string::npos) {
        Straight straight(v);
        straight.calc();
    } else if (v[5].find("yams_") != std::string::npos) {
        Yams yams(v);
        yams.calc();
    } else
        exit(84);
}

void checkError(std::vector<std::string> v)
{
    int i = 0;
    try {
        while (i != v.size() - 1) {
            if (std::stoi(v[i]) > 6)
                throw std::runtime_error("Bad usage");
            i++;
        }
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}
