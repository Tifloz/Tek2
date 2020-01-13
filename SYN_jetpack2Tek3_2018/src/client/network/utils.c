/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include "network.h"

void is_ready(network_t *network)
{
    if (network->b_id == true && network->b_map == true)
        dprintf(network->sock_fd, "READY\n");
}
