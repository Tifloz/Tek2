/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *letter;

    if (!this || !str || !this->str)
        return (-1);
    if (pos > strlen(this->str) - 1)
        return (-1);
    letter = strstr(this->str + pos, str);
    if (!letter)
        return (-1);
    return (int)(letter - this->str);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (!this || !str || !this->str || !str->str)
        return (-1);
    return (find_c(this, str->str, pos));
}
