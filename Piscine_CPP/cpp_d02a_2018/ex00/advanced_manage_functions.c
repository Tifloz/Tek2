/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

bool_t list_add_elem_at_position(list_t *front_ptr, double elem,
    unsigned int position
)
{
    list_t new_elem;
    list_t add_elm;

    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    new_elem = malloc(sizeof(list_t));
    if (new_elem == NULL || *front_ptr == NULL)
        return (FALSE);
    new_elem->value = elem;
    add_elm = *front_ptr;
    for (unsigned int i = 0; add_elm->next != NULL && i != position; i++) {
        add_elm = add_elm->next;
    }
    add_elm->next = new_elem;
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t elem_ptr;
    list_t prev_elem;

    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    else if (position + 1 == list_get_size(*front_ptr))
        return (list_del_elem_at_back(front_ptr));
    if (*front_ptr == NULL)
        return (FALSE);
    elem_ptr = *front_ptr;
    prev_elem = elem_ptr;
    for (unsigned int i = 0; elem_ptr->next != NULL && i != position; i++) {
        prev_elem = elem_ptr;
        elem_ptr = elem_ptr->next;
    }
    prev_elem->next = elem_ptr->next;
    free(elem_ptr);
    return (TRUE);
}