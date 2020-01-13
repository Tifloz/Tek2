/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

string_t **split_s(const string_t *this, char separator)
{
    size_t i = 0;
    char **tab;
    string_t **res;

    if (!this || !this->str)
        return (NULL);
    tab = split_c(this, separator);
    res = NULL;
    for (i = 0; tab != NULL && tab[i++]; ++i) {
        res = realloc(res, (i + 1) * sizeof(string_t));
        res[i] = malloc(sizeof(string_t));
        string_init(res[i], tab[i]);
    }
    res = realloc(res, (i + 1) * sizeof(string_t));
    res[i] = malloc(sizeof(string_t));
    string_init(res[i], 0x0);
    return (res);
}

char **split_c(const string_t *this, char separator)
{
    if (!this || !this->str)
        return (NULL);
    return (my_str_to_wordarray(this->str, separator));
}