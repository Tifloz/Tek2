/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** main.c
*/

#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include "args.h"

typedef struct t_server {
    struct sockaddr_in in;
    int fd;
    fd_set set_fd;
} s_server;

typedef struct t_client {
    int fd;
    struct sockaddr_in in;
    int x;
    int y;
    int score;
    int jetpack;
    int state;
    int id;
    int winner;
} s_client;

//server.c
int create_server(s_args *a, s_server *s, s_client *c);

int server_init(s_args *a, s_server *s);

//handle_commands.c
void new_client(s_server *s, int *max_fd, s_client *c);

void get_message(int client_fd, s_client *c, s_args *a);

void send_message(int fd, char *message, ...);

int exit_state(int mode);

//game.c
void game_supervisor(s_client *c, s_server *s, s_args *a);

#endif