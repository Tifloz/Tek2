/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "response.h"

void set(s_serv *server, s_player *player)
{
    int tmp = find_object(player->act->act_str[0]);
    if (tmp == -1) {
        dprintf(player->fd, "ko\n");
    } else {
        if (player->inv->stock[tmp] > 0) {
            player->inv->stock[tmp]--;
            server->map[player->y][player->x]->stock[tmp]++;
            dprintf(player->fd, response[player->act->acts[0]]);
            if (player->inv->stock[0] <= 0)
                player_die(server, player);
        } else
            dprintf(player->fd, "ko\n");
    }
    if (server->graph->active == 1) {
        print_player(server, player, player->team,
            get_player_pos_by_fd(server, player->fd, player->team));
        print_tile(server, server->map[player->y][player->x],
            player->y, player->x);
    }
    destroy_action(player->act);
}
