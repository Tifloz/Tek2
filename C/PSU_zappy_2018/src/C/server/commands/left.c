/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "response.h"

void left(__attribute__((unused))s_serv *server, s_player *player)
{
    player->lvl->dir--;
    if (player->lvl->dir < 0)
        player->lvl->dir = 3;
    dprintf(player->fd, response[player->act->acts[0]]);
    destroy_action(player->act);
}
