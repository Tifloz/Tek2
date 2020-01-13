/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    unsigned int i = 0;

    while (list != NULL) {
        list = list->next;
        i++;
    }
    return (i);
}

bool_t list_is_empty(list_t list)
{
    return ((list == NULL) ? TRUE : FALSE);
}

void list_dump(list_t list)
{
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}
