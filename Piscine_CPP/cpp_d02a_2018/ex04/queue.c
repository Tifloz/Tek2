/*
** EPITECH PROJECT, 2022
** cpp_d02a_2018
** File description:
** Created by Florian Louvet,
*/
#include "queue.h"
#include "generic_list.h"

unsigned int queue_get_size(queue_t queue)
{
    return (list_get_size(queue));
}

bool_t queue_is_empty(queue_t queue)
{
    return (list_is_empty(queue));
}

bool_t queue_push(queue_t *queue_ptr, void *elem)
{
    return (list_add_elem_at_back(queue_ptr, elem));
}

bool_t queue_pop(queue_t *queue_ptr)
{
    return (list_del_elem_at_front(queue_ptr));
}

void *queue_front(queue_t queue)
{
    return (list_get_elem_at_front(queue));
}