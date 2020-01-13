/*
** EPITECH PROJECT, 2022
** PSU_2018_malloc
** File description:
** Created by Julien Thueux
*/
#include "structure.h"

mem_t *my_struct = NULL;

void init_struc(size_t size)
{
    my_struct = sbrk(sizeof(mem_t) + size);
    my_struct->size = size;
    my_struct->next = NULL;
    my_struct->prev = NULL;
}

void *malloc(size_t size)
{
    mem_t *temp = NULL;
    mem_t *test = NULL;

    if (!size)
        return (NULL);
    if (my_struct == NULL) {
        init_struc(size);
        return (my_struct + sizeof(mem_t));
    }
    temp = my_struct;
    while (temp->next)
        temp = temp->next;
    test = sbrk(sizeof(mem_t) + size);
    test->mem = sbrk(size);
    test->size = size;
    test->next = NULL;
    test->prev = temp;
    temp->next = test;
    return (test + sizeof(mem_t));
}