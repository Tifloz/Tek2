/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void connect_nbr(s_serv *server, s_player *player)
{
    int tmp = 0;

    for (int i = 0; i != (server->max_per_team +
        server->more_player[player->team]); i++) {
        if (server->entry[player->team]->player[i]->active == 1)
            tmp++;
    }
    dprintf(player->fd, "%d\n", ((server->max_per_team +
        server->more_player[player->team]) - tmp));
    destroy_action(player->act);
}
