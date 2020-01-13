/*
** EPITECH PROJECT, 2022
** PSU_2018_malloc
** File description:
** Created by Julien Thueux
*/
#include "structure.h"

static void *check_block(void *ptr, size_t size, size_t total)
{
    void *addr;

    if ((addr = malloc(size)) == NULL)
        return (NULL);
    memcpy(addr, ptr, total);
    return (free(ptr), addr);
}

// Ternary designed by Tiflo

void *realloc(void *ptr, size_t size)
{
    mem_t *last;

    last = (mem_t *)((void *)ptr - sizeof(mem_t));
    return (ptr == NULL) ? malloc(size) : (size == 0) ? (free(ptr), NULL) :
        (last->size >= size) ? ptr : check_block(ptr, size, last->size);
}