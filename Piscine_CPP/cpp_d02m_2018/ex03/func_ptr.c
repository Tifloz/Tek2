/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char temp;
    size_t len = strlen(str) - 1;
    size_t stop = len;
    size_t i, k;

    for (i = 0, k = len; i < stop + 1; i++, k--) {
        printf("%c", str[k]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*functions[4])(const char *) = {print_normal, print_reverse,
        print_upper, print_42};
    functions[action](str);
}