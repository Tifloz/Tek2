/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include <strings.h>
#include <iomanip>
#include "Calc.hpp"

Calc::~Calc() = default;

Calc::Calc(int a, int b)
{
    this->_a = a;
    this->_b = b;
}

void Calc::Arr()
{
    int x;
    int y = 10;
    float sum[6];

    _print.Separator();
    std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;
    bzero(sum, sizeof(float) * 6);
    while (y <= 60) {
        x = 10;
        sum[5] = 0;
        if (y >= 60)
            std::cout << "X law" << std::fixed << std::setprecision(3);
        else
            std::cout << "Y=" << y << std::fixed << std::setprecision(3);
        while (x <= 50) {
            _arr[x / 10 - 1][y / 10 - 1] = (y == 60 ? sum[x / 10 - 1] :
                (float)((_a - x) * (_b - y)) /
                    (float)((5 * _a - 150) * (5 * _b - 150)));
            sum[x / 10 - 1] += _arr[x / 10 - 1][y / 10 - 1];
            std::cout << "\t" << _arr[x / 10 - 1][y / 10 - 1];
            sum[5] += _arr[x / 10 - 1][y / 10 - 1];
            x += 10;
        }
        if (y == 60)
            std::cout << "\t1" << std::endl;
        else
            std::cout << "\t" << sum[5] << std::endl;
        _arr[x / 10 - 1][y / 10 - 1] = sum[5];
        y += 10;
    }
}

void Calc::Zlaw()
{
    int x;
    int y;

    _print.Separator();
    x = 0;
    bzero(_zarr, sizeof(float) * 10);
    std::cout << "z\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal" << std::endl;
    std::cout << "p(Z=z)";
    while (x < 5) {
        y = 0;
        while (y < 5) {
            _zarr[x + y] += _arr[x][y];
            _zarr[9] += _arr[x][y];
            y++;
        }
        x++;
    }
    for (x = 0; x < 9; x++)
        std::cout << "\t" << _zarr[x];
    std::cout << "\t1" << std::endl;
}

void Calc::Variance()
{
    float var[6];
    int i = 0;

    bzero(var, sizeof(float) * 6);
    while (i < 5) {
        var[0] += (i + 1) * 10 * _arr[i][5];
        var[2] += (i + 1) * 10 * _arr[5][i];
        var[4] += (i + 2) * 10 * _zarr[i];
        i++;
    }
    i = 0;
    while (i < 5) {
        var[1] +=
            ((i + 1) * 10 - var[0]) * ((i + 1) * 10 - var[0]) * _arr[i][5];
        var[3] +=
            ((i + 1) * 10 - var[2]) * ((i + 1) * 10 - var[2]) * _arr[5][i];
        if (i < 4)
            var[4] += (i + 7) * 10 * _zarr[i + 5];
        i++;
    }
    i = 0;
    while (i < 9) {
        var[5] += ((i + 2) * 10 - var[4]) * ((i + 2) * 10 - var[4]) * _zarr[i];
        i++;
    }
    _print.Separator();
    _print.Variance(var);
    _print.Separator();
}
