/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_202UNSOLD_CALC_HPP
#define INC_202UNSOLD_CALC_HPP

#include "Printer.hpp"

class Calc {
    public:
    Calc(int a, int b);

    virtual ~Calc();

    void Arr();

    void Zlaw();

    void Variance();

    private:
    int _a;
    int _b;
    Printer _print;
    float _arr[6][6];
    float _zarr[10];
};

#endif //INC_202UNSOLD_CALC_HPP
