/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include "client.h"
#include "network.h"

void cmd_player(char *buf, network_t *network_info)
{
    char **tmp = my_str_to_wordarray(buf, ' ');

    if (network_info->game.players[0].id == atoi(tmp[1])) {
        network_info->game.players[0].x = atof(tmp[2]);
        network_info->game.players[0].y = atof(tmp[3]);
        network_info->game.players[0].coin = atof(tmp[4]);
    } else {
        network_info->game.players[1].id = atoi(tmp[1]);
        network_info->game.players[1].x = atof(tmp[2]);
        network_info->game.players[1].y = atof(tmp[3]);
        network_info->game.players[1].coin = atoi(tmp[4]);
    }
}