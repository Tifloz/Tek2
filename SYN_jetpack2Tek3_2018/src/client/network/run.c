/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include <stdio.h>
#include "network.h"
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include "cmds.h"
#include "get_next_line.h"

int get_cmd(network_t *network, int sock_fd)
{
    char *line;

    if ((line = get_next_line(sock_fd)) != 0) {
        for (int i = 0; cmd_tab[i].name != 0; i++) {
            if (strncmp(cmd_tab[i].name, line, cmd_tab[i].len) == 0) {
                cmd_tab[i].ptr(line, network);
                break;
            }
        }
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

void handle_client(network_t *network_info)
{
    struct timeval tv = {1, 0};

    FD_ZERO(&network_info->fds);
    FD_SET(network_info->sock_fd, &network_info->fds);
    network_info->fd_max = network_info->sock_fd;
    while (network_info->endgame == false) {
        network_info->rdfds = network_info->fds;
        if (select(network_info->fd_max + 1, &network_info->rdfds, NULL, NULL,
            &tv) < 0) {
            fprintf(stderr, "Failed to select\n");
            network_info->error = true;
            pthread_exit((void *)1);
        } else if (FD_ISSET(network_info->sock_fd, &network_info->rdfds))
            get_cmd(network_info,
                network_info->sock_fd) ? network_info->connected = false : 0;
    }
}

void *launch_network(void *args)
{
    struct sockaddr_in s_in;
    network_t *network_info = (network_t *)args;

    if ((network_info->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Failed to create client socket\n");
        pthread_exit((void *)1);
    }
    s_in.sin_addr.s_addr = inet_addr(network_info->ip);
    s_in.sin_port = htons(network_info->port);
    s_in.sin_family = AF_INET;
    if (connect(network_info->sock_fd, (struct sockaddr *)&s_in, sizeof(s_in)) <
        0) {
        fprintf(stderr, "Failed to connect to server\n");
        network_info->endgame = network_info->error = true;
        pthread_exit((void *)1);
    }
    network_info->connected = true;
    dprintf(network_info->sock_fd, "ID\n");
    dprintf(network_info->sock_fd, "MAP\n");
    handle_client(network_info);
    pthread_exit(0);
}