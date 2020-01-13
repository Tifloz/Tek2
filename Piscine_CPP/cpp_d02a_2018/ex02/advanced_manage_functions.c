/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include "generic_list.h"

bool_t list_add_elem_at_position(list_t *front_ptr, void *elem,
    unsigned int position
)
{
    list_t new;
    list_t add_elm;

    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (*front_ptr == NULL)
        return (FALSE);
    new = malloc(sizeof(list_t));
    if (new == NULL)
        return (FALSE);
    new->value = elem;
    add_elm = *front_ptr;
    for (unsigned int i = 0; add_elm->next != NULL && i != position; i++) {
        add_elm = add_elm->next;
    }
    add_elm->next = new;
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

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL)
        return (NULL);
    for (unsigned int i = 0; list->next != NULL && i != position; i++) {
        list = list->next;
    }
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t val_comp
)
{
    while (list != NULL) {
        if ((val_comp)(list->value, value) == 0)
            return (list);
        list = list->next;
    }
    return (NULL);
}