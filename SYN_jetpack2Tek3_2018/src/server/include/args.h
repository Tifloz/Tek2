/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** args.h
*/

#ifndef ARGS_H
#define ARGS_H

typedef struct t_args {
    int port;
    float gravity;
    char *map;
    char *clean_map;
    int width;
    int height;
    int game_status;
} s_args;

int check_args(int ac, char **av, s_args *args);

int get_map_size(char *filename);

void check_map_file(char *filename, s_args *args);

int check_map(s_args *args);

void create_clean_map(s_args *a);

#endif