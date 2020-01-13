/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "stack.h"
#include "generic_list.h"
#include <stdlib.h>

unsigned int stack_get_size(stack_t stack)
{
    return (list_get_size(stack));
}

bool_t stack_is_empty(stack_t stack)
{
    return (list_is_empty(stack));
}

bool_t stack_push(stack_t *stack_ptr, void *elem)
{
    return (list_add_elem_at_front(stack_ptr, elem));
}

bool_t stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_front(stack_ptr));
}

void *stack_top(stack_t stack)
{
    return (list_get_elem_at_front(stack));
}