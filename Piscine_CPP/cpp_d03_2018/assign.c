/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (!this || !s)
        return;
    if (this->str)
        free(this->str);
    this->str = strdup(s);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this && str)
        assign_c(this, str->str);
}