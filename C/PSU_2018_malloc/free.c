/*
** EPITECH PROJECT, 2022
** PSU_2018_malloc
** File description:
** Created by Julien Thueux
*/

#include "structure.h"

void free(void *ptr)
{
    mem_t *temp = NULL;

    if (!ptr)
        return;
    temp = (mem_t *)ptr - sizeof(mem_t);

    memset(ptr, 0, temp->size);
    if (!(temp->next)) {
        if (temp->prev) {
            temp->prev->next = NULL;
        }
    } else {
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
    }
    memset(temp, 0, sizeof(mem_t));
}