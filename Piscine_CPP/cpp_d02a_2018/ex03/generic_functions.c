/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include "generic_list.h"

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
    if (list == NULL)
        return (TRUE);
    return (FALSE);
}

void list_clear(list_t *front_ptr)
{
    *front_ptr = NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list != NULL) {
        (val_disp)(list->value);
        list = list->next;
    }
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (NULL);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}
