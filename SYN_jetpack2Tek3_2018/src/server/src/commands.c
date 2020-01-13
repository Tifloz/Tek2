/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** commands_one.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"

void id_command(s_client *c, s_args *a, int fd, const char *msg)
{
    (void)a;
    (void)msg;
    int id = c[0].fd == fd ? c[0].id : c[1].id;

    send_message(fd, "ID %d\n", id);
}

void map_command(s_client *c, s_args *a, int fd, const char *msg)
{
    (void)msg;
    (void)c;

    send_message(fd, "MAP %d %d %s\n", a->width, a->height, a->clean_map);
}

void ready_command(s_client *c, s_args *a, int fd, const char *msg)
{
    (void)msg;
    int player = c[0].fd == fd ? 1 : 2;

    if (player == 1)
        c->state = 1;
    else
        c[1].state = 1;
    if (c[0].state == c[1].state) {
        send_message(c[0].fd, "START\n");
        send_message(c[1].fd, "START\n");
        a->game_status = 1;
    }
}

void fire_command(s_client *c, s_args *a, int fd, char *msg)
{
    (void)a;
    int player = c[0].fd == fd ? 1 : 2;
    char **splitted = str_to_word_tab(msg, ' ');

    if (strcmp(splitted[1], "0\r") == 0) {
        if (player == 1)
            c[0].jetpack = 0;
        else
            c[1].jetpack = 0;
    } else {
        if (player == 1)
            c[0].jetpack = 1;
        else
            c[1].jetpack = 1;
    }
    for (int i = 0; splitted[i]; i++)
        free(splitted[i]);
}