/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#include <string>
#include <iostream>
#include <cmath>
#include "Parser.hpp"
#include "Printer.hpp"
#include "Calc.hpp"

Parser::Parser() = default;;

Parser::~Parser() = default;

bool Parser::IsANumber(char *str)
{
    int i = 0;

    while (str[i]) {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            i++;
        else if (str[i] < '0' || str[i] > '9')
            return (false);
        else
            i++;
    }
    return (true);
}

void Parser::Launch(int ac, char **av)
{
    Printer print;
    int i = 1;
    int args[9];

    while (i < ac) {
        if (std::string("-h") == av[1])
            print.Usage();
        if (!IsANumber(av[i]))
            print.Error();
        errno = 0;
        args[i - 1] = atoi(av[i]);
        if (errno == ERANGE)
            print.Error();
        i++;
    }
    if (i != 10)
        print.Error();
    for (int j = 0; j < 10; j++)
        if (args[j] < 0)
            print.Error();
    Calc *calc = new Calc(args);
}