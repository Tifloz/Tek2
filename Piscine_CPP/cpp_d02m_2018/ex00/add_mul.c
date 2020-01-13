/*
** EPITECH PROJECT, 2022
** cpp_d02m_2018
** File description:
** Created by Florian Louvet,
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int tmp = *first;
    *first = tmp + *second;
    *second = tmp * *second;
}