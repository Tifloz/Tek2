/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

int to_int(const string_t *this)
{
    return ((!this || !this->str) ? 0 : (atoi(this->str)));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;
    size_t len;

    if (!this || !s || !this->str)
        return (0);
    len = strlen(this->str);
    while (i + pos < len && i < n) {
        s[i] = this->str[i + pos];
        i++;
    }
    if (strlen(s) < n)
        s[i++] = 0;
    return (i);
}

void clear(string_t *this)
{
    if (!this || !this->str)
        return;
    for (int i = 0; this->str[i] != '\0'; i++) {
        this->str[i] = '\0';
    }
}

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (int)(strlen(this->str));
}

char at(const string_t *this, size_t pos)
{
    if (!this || !this->str || pos > strlen(this->str) - 1)
        return (-1);
    return (this->str[pos]);
}