/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_202UNSOLD_CALC_HPP
#define INC_202UNSOLD_CALC_HPP

#include "Printer.hpp"
#include <iostream>
#include <string>

class Calc {
    public:
    Calc(double a, double n, double h, double sd, std::string line);

    virtual ~Calc();
    double SDeviation();

    double ArithmeticMean();

    void RootMean();

    double HarmonicMean();
    private:
    double _n;
    double _a;
    double _h;
    double _sd;
    double _mult;
    double _power;
    double _root;
    std::string _line;

    Printer _print;

    void Final();
};

#endif //INC_202UNSOLD_CALC_HPP
