/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#include "menger.h"

void menger(int size, int abscissa, int x, int y)
{
    int next = size / 3;

    if (size == 0 || abscissa % 3 != 0 || abscissa != 0) {
        printf("%03d %03d %03d\n", next, x + next, y + next);
        menger(next, abscissa - 1, x, y);
        menger(next, abscissa - 1, x, y + next);
        menger(next, abscissa - 1, x, y + 2 * next);
        menger(next, abscissa - 1, x + next, y);
        menger(next, abscissa - 1, x + next, y + next);
        menger(next, abscissa - 1, x + next, y + 2 * next);
        menger(next, abscissa - 1, x + 2 * next, y + next);
        menger(next, abscissa - 1, x + 2 * next, y + 2 * next);
    }
}