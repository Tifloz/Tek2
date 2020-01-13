/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D01_2018_DRAWING_H
#define CPP_D01_2018_DRAWING_H

# include <string.h>
# include <stdint.h>

typedef struct point {
    uint32_t x;
    uint32_t y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size,
    uint32_t color
);

#endif //CPP_D01_2018_DRAWING_H
