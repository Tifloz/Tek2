/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** server.c
*/

#include <stdio.h>
#include <args.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include "server.h"
#include "commands.h"

int server_init(s_args *a, s_server *s)
{
    s->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s->fd == -1) {
        fprintf(stderr, "socket error\n");
        exit(84);
    }
    s->in.sin_family = AF_INET;
    s->in.sin_addr.s_addr = INADDR_ANY;
    s->in.sin_port = htons(a->port);
    if (bind(s->fd, (struct sockaddr *)&s->in, sizeof(s->in)) < 0) {
        fprintf(stderr, "bind socket error\n");
        exit(84);
    }
    if (listen(s->fd, 3) == -1) {
        fprintf(stderr, "can't listen to socket\n");
        exit(84);
    }
    return (0);
}

void add_clients_to_set(s_server *s, s_client *c)
{
    FD_ZERO(&s->set_fd);
    FD_SET(s->fd, &s->set_fd);
    if (c[0].fd > 0)
        FD_SET(c[0].fd, &s->set_fd);
    if (c[1].fd > 0)
        FD_SET(c[1].fd, &s->set_fd);
}

void server_loop(s_args *a, s_server *s, s_client *c)
{
    int max_fd = s->fd;
    struct timeval tv = {0, 1};
    tv.tv_sec = (10);

    printf("Server launched !\nPort : %d\n", a->port);
    while (1) {
        add_clients_to_set(s, c);
        if (select(max_fd + 1, &s->set_fd, NULL, NULL, &tv) == -1) {
            perror("select");
            exit(84);
        }
        if (FD_ISSET(s->fd, &s->set_fd))
            new_client(s, &max_fd, c);
        if (FD_ISSET (c[0].fd, &s->set_fd))
            get_message(c[0].fd, c, a);
        if (FD_ISSET (c[1].fd, &s->set_fd))
            get_message(c[1].fd, c, a);
    }
}

int create_server(s_args *args, s_server *s, s_client *c)
{
    c[0].x = 0;
    c[0].y = args->height / 2;
    c[1].x = 0;
    c[1].y = args->height / 2;
    server_init(args, s);
    FD_ZERO(&s->set_fd);
    server_loop(args, s, c);
    return (0);
}