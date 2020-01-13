/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_JETPACK2TEK3_2018_NETWORK_H
#define SYN_JETPACK2TEK3_2018_NETWORK_H

#include <stdbool.h>
#include <arpa/inet.h>
#include "parser.h"
#include "client.h"
#include <sys/select.h>

typedef struct network_s {
    int width;
    int height;
    int fd_max;
    int port;
    int sock_fd;
    int id;
    bool b_id;
    bool b_map;
    bool start;
    char *ip;
    char **map;
    fd_set fds;
    fd_set rdfds;
    pthread_t net_thread;
    bool endgame;
    bool error;
    bool connected;
    game_t game;
} network_t;

int run(network_t *net);

void is_ready(network_t *network);

int init_texts(network_t *network);

void draw_text(network_t *network);

void *launch_network(void *args);

#endif
