/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = malloc(sizeof(int *) * length + 1);
    int pos = 0;
    for (int i = 0; i < length; i++) {
        (*res)[i] = malloc(sizeof(int) * width + 1);
        for (int j = 0; j < width; j++) {
            (*res)[i][j] = tab[pos++];
        }
    }
}