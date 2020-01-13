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
    int args[4];

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
    if (i != 5 || args[0] < 0 || args[1] < 0 || args[2] <= 0 || args[3] < 0)
        print.Error();
    Parser::Loop(args[0], args[1], args[2], args[3]);
}

void Parser::Loop(double n, double a, double h, double sd)
{
    std::string line;
    Printer print;

    std::cout << "Enter next value: ";
    while (std::cin >> line) {
        if (line == "END")
            exit(0);
        Calc *calc = new Calc(a, n, h, sd, line);
        a = calc->ArithmeticMean();
        sd = calc->SDeviation();
        calc->RootMean();
        h = calc->HarmonicMean();
        delete calc;
        n++;
        print.Separator();
        std::cout << "Enter next value: ";
    }
}
