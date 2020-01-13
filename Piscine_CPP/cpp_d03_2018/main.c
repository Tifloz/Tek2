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

int main()
{
    string_t s;
    string_t tester;
    string_init(&s, "");
    string_init(&tester, "");
    // EX01
    assign_c(&s, "BUH");
    if (!strcmp(s.str, "BUH")) {
        assign_c(&tester, "test");
        assign_s(&s, &tester);
        if (!strcmp(s.str, "test"))
            printf("Ex01 Passed\n");
    }
    // EXO2
    append_c(&s, "BUH");
    if (!strcmp(s.str, "testBUH")) {
        append_s(&s, &tester);
        if (!strcmp(s.str, "testBUHtest"))
            printf("Ex02 Passed\n");
    }
    string_destroy(&s);
    string_destroy(&tester);
    return (0);
}