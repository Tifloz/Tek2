/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t new_elem;

    if ((new_elem = malloc(sizeof(list_t))) == NULL)
        return (FALSE);
    new_elem->value = elem;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t last_elem;
    list_t new_elem;

    if ((last_elem = malloc(sizeof(list_t))) == NULL)
        return (FALSE);
    last_elem->next = NULL;
    last_elem->value = elem;
    if (*front_ptr == NULL)
        return (list_add_elem_at_front(front_ptr, elem));
    new_elem = *front_ptr;
    while (new_elem->next != NULL)
        new_elem = new_elem->next;
    new_elem->next = last_elem;
    return (TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    if (*front_ptr == NULL)
        return (FALSE);
    *front_ptr = (*front_ptr)->next;
    if (*front_ptr == NULL)
        return (FALSE);
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t last_elm;

    if (*front_ptr == NULL)
        return (FALSE);
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return (FALSE);
    }
    last_elm = *front_ptr;
    while (last_elm->next->next != NULL)
        last_elm = last_elm->next;
    last_elm->next = NULL;
    return (TRUE);
}