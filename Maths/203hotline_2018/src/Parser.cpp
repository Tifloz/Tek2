/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#include <string>
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
    int args[2];

    while (i < ac) {
        if (std::string("-h") == av[1])
            print.Usage();
        if (i > 2 || !IsANumber(av[i]))
            print.Error();
        errno = 0;
        args[i - 1] = atoi(av[i]);
        if (errno == ERANGE)
            print.Error();
        i++;
    }
    if (i != 3 || args[0] <= 50 || args[1] <= 50)
        print.Error();
    Calc calc(args[0], args[1]);
    calc.Arr();
    calc.Zlaw();
    calc.Variance();
}
