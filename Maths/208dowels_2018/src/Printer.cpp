/*
** EPITECH PROJECT, 2022
** 202unsold_2018
** File description:
** Created by Florian Louvet,
*/

#include <iostream>
#include <iomanip>
#include "Printer.hpp"

Printer::Printer() = default;

void Printer::Usage()
{
    std::cout << "USAGE" << std::endl
        << "\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8" << std::endl << std::endl
        << "DESCRIPTION" << std::endl << "\tOi   size of the observed class"
        << std::endl;
    exit(0);
}

void Printer::Error()
{
    std::cerr << "Error: Bad arguments" << std::endl;
    exit(84);
}

void Printer::Separator()
{
    std::cout << std::endl;
}

void Printer::Final(double n, double sd, double a, double root, double h)
{
}

Printer::~Printer() = default;


