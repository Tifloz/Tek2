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
    std::cout << "USAGE" << std::endl << "\t./203hotline [n k | d]" << std::endl
        << std::endl << "DESCRIPTION" << std::endl
        << "\tn\tn value for the computation of(n|k)" << std::endl
        << "\tk\tk value for the computation of(n|k)" << std::endl
        << "\td\taverage duration of calls (in seconds)" << std::endl;
    exit(0);
}

void Printer::Error()
{
    std::cerr << "Error: Bad arguments" << std::endl;
    exit(84);
}

void Printer::Separator()
{
    std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
        << std::endl;
}

void Printer::Variance(float *var)
{
    std::cout << std::setprecision(1);
    std::cout << "expected value of X:\t" << var[0] << std::endl;
    std::cout << "variance of X:\t\t" << var[1] << std::endl;
    std::cout << "expected value of Y:\t" << var[2] << std::endl;
    std::cout << "variance of Y:\t\t" << var[3] << std::endl;
    std::cout << "expected value of Z:\t" << var[4] << std::endl;
    std::cout << "variance of Z:\t\t" << var[5] << std::endl;
}

Printer::~Printer() = default;


