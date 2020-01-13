/*
** EPITECH PROJECT, 2022
** cpp_d01_2018
** File description:
** Created by Florian Louvet,
*/
#include "menger.h"

int check_digits(char c)
{
    if (c >= 48 && c <= 57)
        return (0);
    return (1);
}

int my_atoi(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (check_digits(str[i]) == 0)
            res = res * 10 + (str[i] - 48);
        else
            return (-84);
        i++;
    }
    return (sign * res);
}

int error_handler(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (my_atoi(av[1]) == -84 || my_atoi(av[2]) == -84 || my_atoi(av[2]) > 3)
        return (1);
    if (my_atoi(av[1]) < pow(my_atoi(av[2]), 3))
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (error_handler(ac, av) == 1) {
        printf(
            "Usage: ./menger size_of_original_square number_of_levels\n");
        return (84);
    }
    menger(my_atoi(av[1]), my_atoi(av[2]), 0, 0);
    return (0);
}