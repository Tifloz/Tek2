/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include <strings.h>
#include <iomanip>
#include <cmath>
#include "Calc.hpp"

Calc::~Calc()
{
    _print.Final(_n, _sd, _a, _root, _h);
};

double Calc::ArithmeticMean()
{
    _a = (_mult + atof(_line.c_str())) / _n;
    return _a;
}

void Calc::RootMean()
{
    _root = sqrt((_power + pow(atof(_line.c_str()), 2)) / _n);
}

double Calc::HarmonicMean()
{
    _h = _n / ((1 / atof(_line.c_str())) + ((_n - 1) / _h));
    return _h;
}

double Calc::SDeviation()
{
    _sd =
        sqrt(((_power + pow(atof(_line.c_str()), 2)) / _n) - pow(_a, 2)) * 1.0;
    return _sd;
}

Calc::Calc(double a, double n, double h, double sd, std::string line)
{
    _a = a;
    _n = n;
    _h = h;
    _sd = sd;
    _root = 0;
    _line = line;
    _mult = _a * _n;
    _power = (pow(_sd, 2) + pow(_a, 2)) * _n;
    _n++;
}
