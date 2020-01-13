/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** server.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void new_client(s_server *s, int *max_fd, s_client *c)
{
    int socket = 0;
    struct sockaddr_in in;
    socklen_t len = sizeof(in);
    static int nb_client = -1;

    nb_client++;
    if (nb_client > 1)
        return;
    socket = accept(s->fd, (struct sockaddr *)&in, &len);
    if (socket == -1) {
        printf("Can't accept client");
        exit(84);
    }
    printf("Client connected !\n");
    c[nb_client].fd = socket;
    *max_fd = c[nb_client].fd > *max_fd ? c[nb_client].fd : *max_fd;
    c[nb_client].in = in;
    c[nb_client].id = *max_fd + 1;
}