/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    int res = a / b;
    return (res);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0.0f);
    float res = (float)a / (float)b;
    return (res);
}

void exec_div(division_t *operation)
{
    switch (operation->div_type) {
    case INTEGER:
        ((integer_op_t *)operation->div_op)->res = integer_div(
            ((integer_op_t *)operation->div_op)->a,
            ((integer_op_t *)operation->div_op)->b);
        break;
    case DECIMALE:
        ((decimale_op_t *)operation->div_op)->res = decimale_div(
            ((decimale_op_t *)operation->div_op)->a,
            ((decimale_op_t *)operation->div_op)->b);
        break;
    }
}