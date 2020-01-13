/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "response.h"

void right(s_serv *server, s_player *player)
{
    player->lvl->dir++;
    if (player->lvl->dir > 3)
        player->lvl->dir = 0;
    dprintf(player->fd, response[player->act->acts[0]]);
    if (server->graph->active == 1) {
        print_player(server, player,
            player->team, get_player_pos_by_fd(server,
                player->fd, player->team));
    }
    destroy_action(player->act);
}
