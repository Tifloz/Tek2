/*
** EPITECH PROJECT, 2018
** GATEAN CHAUGNY
** File description:
** take a char* and return a char**
*/

#include <unistd.h>
#include <stdlib.h>
#include "commands.h"

int get_pos(char *str, int index, char c)
{
    int len = 0;
    int nb_char = 0;

    if (index == 0)
        return (0);
    for (int i = 0; nb_char < index && str[i]; i++) {
        if (str[i] == c)
            nb_char++;
        len++;
    }
    return (len);
}

int get_size(char *str, char c)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            size++;
    }
    return (size + 1);
}

char *get_word(char *str, char c)
{
    int len = 0;
    char *new = NULL;

    for (int i = 0; str[i] != c && str[i]; i++)
        len++;
    if (!(new = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    for (int i = 0; str[i] != c && str[i]; i++)
        new[i] = str[i];
    new[len] = 0;
    return (new);
}

char **str_to_word_tab(char *str, char c)
{
    int pos = 0;
    int size = get_size(str, c);
    char **tab = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size + 1; i++) {
        pos = get_pos(str, i, c);
        tab[i] = get_word(&str[pos], c);
        if (!tab[i])
            return (NULL);
    }
    tab[size] = NULL;
    return (tab);
}