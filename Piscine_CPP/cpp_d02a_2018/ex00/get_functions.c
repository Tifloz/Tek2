/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

double list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0.0);
    return (list->value);
}

double list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0.0);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL)
        return (0.0);
    if (position == 0)
        return (list_get_elem_at_front(list));
    for (unsigned int i = 0; list->next != NULL && i < position; i++) {
        list = list->next;
    }
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    while (list != NULL) {
        if (list->value == value)
            return (list);
        list = list->next;
    }
    return (NULL);
}