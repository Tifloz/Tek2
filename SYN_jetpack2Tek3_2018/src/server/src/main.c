/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "args.h"
#include "server.h"

void init_struct(s_args *args, s_server *server, s_client *c)
{
    args->port = 0;
    args->gravity = 9.8;
    args->map = NULL;
    args->clean_map = NULL;
    args->height = 0;
    args->width = 0;
    args->game_status = 0;
    server->fd = 0;
    c[0].fd = 0;
    c[0].state = 0;
    c[0].x = 0;
    c[0].y = 0;
    c[1].fd = 0;
    c[1].state = 0;
    c[1].x = 0;
    c[1].y = 0;
    c[1].y = 0;
}

int main(int ac, char **av)
{
    struct t_args args;
    struct t_server server;
    struct t_client c[2];

    if (ac != 7) {
        fprintf(stderr, "Invalid number of arguments\n");
        return (84);
    }
    init_struct(&args, &server, c);
    check_args(ac, av, &args);
    create_server(&args, &server, c);
    return (0);
}