/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <malloc.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    *res = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    strcpy(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = malloc(
        (strlen(str_op->str1) + strlen(str_op->str2) + 1) * sizeof(char));
    strcpy(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}