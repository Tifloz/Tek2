/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** error_management.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include "args.h"

void check_args_values(s_args *args)
{
    if (args->port <= 0 || args->gravity <= 0) {
        fprintf(stderr, "Bad arguments\n");
        exit(84);
    }
    if (args->map == NULL) {
        fprintf(stderr, "Bad map\n");
        exit(84);
    }
}

int check_args(int ac, char **av, s_args *args)
{
    int opt = 0;

    while ((opt = getopt(ac, av, "p:g:m:")) != -1)
        switch (opt) {
        case 'p':
            args->port = atoi(optarg);
            break;
        case 'g':
            args->gravity = atoi(optarg);
            break;
        case 'm':
            check_map_file(optarg, args);
            break;
        case '?':
            exit(84);
        }
    check_args_values(args);
    check_map(args);
    create_clean_map(args);
    return (0);
}

void create_clean_map(s_args *a)
{
    int counter = 0;
    char *cpy = NULL;

    for (int i = 0; a->map[i] != '\0'; i++)
        if (a->map[i] == '\n')
            counter++;
    cpy = malloc(sizeof(char) * (strlen(a->map) + 1 - counter));
    counter = 0;
    for (int i = 0; a->map[i] != '\0'; i++) {
        if (a->map[i] == '\n')
            continue;
        cpy[counter] = a->map[i];
        counter++;
    }
    cpy[counter] = '\0';
    a->clean_map = cpy;
}