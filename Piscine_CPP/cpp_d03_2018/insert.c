/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp;
    size_t len = 0;

    if (!this || !str)
        return;
    (this->str) ? len = strlen(this->str) : 0;
    (len < pos) ? pos = len : 0;
    tmp = malloc(sizeof(char) * (len + strlen(str) + 1));
    strncpy(tmp, this->str, pos);
    strcat(tmp, str);
    if (pos != strlen(this->str))
        strcat(tmp, this->str + pos);
    free(this->str);
    this->str = tmp;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return ((!this || !str || !str->str) ? 0 : insert_c(this, pos, str->str));
}
