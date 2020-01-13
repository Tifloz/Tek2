/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include <string.h>
#include <stdlib.h>
#include "client.h"

static int get_nb(char *str, char sep)
{
    int i = 0;
    int j = 0;

    while (str[i] != 0) {
        if (str[i] == sep)
            j++;
        i++;
    }
    return (j);
}

char **my_str_to_wordarray(char *str, char sep)
{
    int i = 0;
    char c[2] = {sep, 0};
    char *tmp;
    char **tab;

    tab = malloc(sizeof(char *) * (get_nb(str, sep) + 2));
    if (tab == NULL)
        return (NULL);
    while ((tmp = strtok(i == 0 ? str : NULL, c))) {
        tab[i] = tmp;
        i++;
    }
    tab[i] = 0;
    return (tab);
}