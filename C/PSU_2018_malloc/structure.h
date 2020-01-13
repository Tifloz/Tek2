/*
** EPITECH PROJECT, 2022
** PSU_2018_malloc
** File description:
** Created by Julien Thueux,
*/

#ifndef PSU_2018_MALLOC_STRUCTURE_H
#define PSU_2018_MALLOC_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct mem_s {
    size_t size;
    void *mem;
    struct mem_s *next;
    struct mem_s *prev;
} mem_t;

extern mem_t *my_struct;

#endif //PSU_2018_MALLOC_STRUCTURE_H