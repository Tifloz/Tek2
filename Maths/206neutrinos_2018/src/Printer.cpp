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
    std::cout << "USAGE" << std::endl << "\t./206neutrinos n a h sd"
        << std::endl << std::endl << "DESCRIPTION" << std::endl
        << "\tn\tnumber of values" << std::endl << "\ta\tarithmetic mean"
        << std::endl << "\th\tharmonic mean" << std::endl
        << "\tsd\tstandard deviation" << std::endl;

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
    printf("\tNumber of values:\t%0.f\n", n);
    printf("\tStandard deviation:\t%.2f\n", sd);
    printf("\tArithmetic mean:\t%.2f\n", a);
    printf("\tRoot mean square:\t%.2f\n", root);
    printf("\tHarmonic mean:\t\t%.2f\n", h);
}

Printer::~Printer() = default;


