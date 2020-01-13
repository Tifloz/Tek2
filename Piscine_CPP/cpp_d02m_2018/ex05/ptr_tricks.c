/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    return (ptr2 - ptr1);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t *temp;

    return ((whatever_t *)((member_ptr - (&temp->member - (int *)temp))));
}