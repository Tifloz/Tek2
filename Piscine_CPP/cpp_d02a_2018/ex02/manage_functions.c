/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include "generic_list.h"

bool_t list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new;

    if ((new = malloc(sizeof(list_t))) == NULL)
        return (FALSE);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t _elem;
    list_t new;

    if ((_elem = malloc(sizeof(list_t))) == NULL)
        return (FALSE);
    _elem->next = NULL;
    _elem->value = elem;
    if (*front_ptr == NULL)
        return (list_add_elem_at_front(front_ptr, elem));
    new = *front_ptr;
    while (new->next != NULL)
        new = new->next;
    new->next = _elem;
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
    list_t _elm;

    if (*front_ptr == NULL)
        return (FALSE);
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return (FALSE);
    }
    _elm = *front_ptr;
    while (_elm->next->next != NULL)
        _elm = _elm->next;
    _elm->next = NULL;
    return (TRUE);
}

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (NULL);
    return (list->value);
}
