/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size,
    uint32_t color
)
{
    size_t y = 0;
    size_t x = 0;

    for (y = origin->y; y < origin->y + size; ++y) {
        for (x = origin->x; x < origin->x + size; ++x)
            img[y][x] = color;
    }
}