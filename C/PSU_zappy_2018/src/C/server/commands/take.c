/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "object.h"
#include "response.h"

int find_object(char *str)
{
    if (str == NULL)
        return -1;

    for (int i = 0; i != OBJ_SIZE; i++) {
        if (strcmp(str, object[i]) == 0)
            return i;
    }
    return -1;
}

void take(s_serv *server, s_player *player)
{
    int tmp = find_object(player->act->act_str[0]);

    if ( tmp == -1) {
        dprintf(player->fd, "ko\n");
    } else {
        if (server->map[player->y][player->x]->stock[tmp] > 0) {
            server->map[player->y][player->x]->stock[tmp]--;
            player->inv->stock[tmp]++;
            dprintf(player->fd, response[player->act->acts[0]]);
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
