/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "response.h"

int get_j_print(s_player *player, s_serv *server, int i)
{
    for (int j = 0; server->entry[i]->player[j] != NULL; j++) {
        if (server->entry[i]->player[j]->fd == player->fd)
            return j;
    }
    return 0;
}

void forward(s_serv *server, s_player *player)
{
    player_move_on_map(server, player, player->lvl->dir);
    dprintf(player->fd, response[player->act->acts[0]]);
    if (server->graph->active == 1)
        print_player(server, player, player->team,
            get_j_print(player, server, player->team));
    destroy_action(player->act);
}
