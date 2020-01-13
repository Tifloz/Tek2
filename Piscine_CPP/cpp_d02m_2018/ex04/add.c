/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include "castmania.h"
#include <stdlib.h>

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    return (int)(abs(a) + abs(b));
}

void exec_add(addition_t *operation)
{
    switch (operation->add_type) {
    case NORMAL:
        operation->add_op.res = normal_add(operation->add_op.a,
            operation->add_op.b);
        break;
    case ABSOLUTE:
        operation->add_op.res = absolute_add(operation->add_op.a,
            operation->add_op.b);
        break;
    }
}