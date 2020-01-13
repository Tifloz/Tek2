/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this && !str)
        return (0);
    if (str)
        return (compare_c(this, str->str));
    return (compare_c(this, NULL));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this)
        return (-1);
    if (this->str && !str)
        return (1);
    if (!this->str && str)
        return (-1);
    if (!this->str && !str)
        return (0);
    return (strcmp(this->str, str));
}