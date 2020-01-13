/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include "client.h"
#include "network.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void cmd_id(char *buf, network_t *network_info)
{
    char **tmp = my_str_to_wordarray(buf, ' ');

    network_info->id = atoi(tmp[1]);
    if (network_info->game.players[0].id == 0)
        network_info->game.players[0].id = atoi(tmp[1]);
    else
        network_info->game.players[1].id = atoi(tmp[1]);
    network_info->b_id = true;
    is_ready(network_info);
}

// TODO: Find a way to verif malloc according to coding style
void cmd_map(char *buf, network_t *network_info)
{
    int j = 0;
    int k = 0;
    char **tmp = my_str_to_wordarray(buf, ' ');

    if (network_info->map)
        return;
    network_info->width = atoi(tmp[1]);
    network_info->height = atoi(tmp[2]);
    network_info->map = malloc(sizeof(char *) * network_info->height);
    if (!network_info->map)
        return;
    for (int i = 0; i < network_info->height; i++) {
        j = 0;
        network_info->map[i] = malloc(sizeof(char) * network_info->width);
        if (!network_info->map[i])
            return;
        while (tmp[3][k] && j < network_info->width)
            network_info->map[i][j++] = tmp[3][k++];
    }
    network_info->b_map = true;
    is_ready(network_info);
}

void cmd_coin(char *buf, network_t *network_info)
{
    char **tmp = my_str_to_wordarray(buf, ' ');
    int x = atoi(tmp[2]);
    int y = atoi(tmp[3]);

    if (x < network_info->width && x >= 0 && y < network_info->height && y >= 0)
        network_info->map[network_info->height - 1 - y][x] = '_';
}

void cmd_finish(char *buf, network_t *network_info)
{
    char **tmp = my_str_to_wordarray(buf, ' ');

    if (atoi(tmp[1]) == network_info->id)
        printf("You win !\n");
    else if (strcmp(tmp[1], "-1") == 0)
        printf("Nobody wins\n");
    else
        printf("You loose\n");
    close(network_info->sock_fd);
    exit(0);
}

void cmd_start(char *buf, network_t *network_info)
{
    network_info->start = true;
    (void)buf;
}