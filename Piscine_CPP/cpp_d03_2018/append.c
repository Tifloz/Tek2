/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

void append_c(string_t *this, const char *ap)
{
    size_t len = 0;
    size_t ap_len = 0;

    if (!this || !ap)
        return;
    if (this->str)
        len = strlen(this->str);
    ap_len = strlen(ap);
    this->str = realloc(this->str, len + ap_len + 1);
    memset(this->str + len, 0, ap_len + 1);
    if (!this->str)
        free(this->str);
    this->str = strcat(this->str, ap);
}

void append_s(string_t *this, const string_t *ap)
{
    if (this && ap)
        append_c(this, ap->str);
}
