/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_JETPACK2TEK3_2018_CMDS_H
#define SYN_JETPACK2TEK3_2018_CMDS_H

#include "network.h"

typedef struct cmd_s {
    char *name;
    int len;

    void (*ptr)();
} cmd_t;

void cmd_coin(char *buf, network_t *network_info);

void cmd_finish(char *buf, network_t *network_info);

void cmd_start(char *buf, network_t *network_info);

void cmd_id(char *buf, network_t *network_info);

void cmd_map(char *buf, network_t *network_info);

void cmd_player(char *buf, network_t *network_info);

cmd_t cmd_tab[] = {{"ID ", 3, cmd_id}, {"MAP ", 4, cmd_map},
    {"COIN ", 5, cmd_coin}, {"FINISH ", 7, cmd_finish}, {"START", 5, cmd_start},
    {"PLAYER ", 7, cmd_player}};

#endif
