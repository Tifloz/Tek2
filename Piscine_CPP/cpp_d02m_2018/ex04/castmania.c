/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    switch (instruction_type) {
    case ADD_OPERATION:
        exec_add((addition_t *)((instruction_t *)data)->operation);
        if (((instruction_t *)data)->output_type == VERBOSE)
            printf("%d\n",
                ((addition_t *)((instruction_t *)data)->operation)->add_op.res);
        break;
    case DIV_OPERATION:
        exec_div((division_t *)(((instruction_t *)data)->operation));
        if (((division_t *)((instruction_t *)data)->operation)->div_type ==
            DECIMALE)
            printf("%f\n", ((decimale_op_t *)((division_t *)((instruction_t *)
            data)->operation)->div_op)->res);
        else if (
            ((division_t *)((instruction_t *)data)->operation)->div_type ==
                INTEGER)
            printf("%d\n", ((integer_op_t *)((division_t *)
                ((instruction_t *)data)->operation)->div_op)->res);
        break;
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    switch (instruction_type) {
    case PRINT_INT:
        printf("%d\n", *((int *)data));
        break;
    case PRINT_FLOAT:
        printf("%f\n", *((float *)data));
        break;
    default:
        exec_operation(instruction_type, data);
    }
}