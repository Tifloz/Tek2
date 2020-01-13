/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "object.h"

void look(s_serv *server, s_player *player)
{
    char to_send[8192] = "[\0";

    memset(to_send + strlen(to_send), 0, 4096 - strlen(to_send));
    get_tile_look(server, to_send, player->x, player->y);
    if (player->lvl->dir == 0) {
        look_up(server, player, player->lvl->lvl, to_send);
    } else if (player->lvl->dir == 1) {
        look_down(server, player, player->lvl->lvl, to_send);
    } else if (player->lvl->dir == 2) {
        look_right(server, player, player->lvl->lvl, to_send);
    } else if (player->lvl->dir == 3) {
        look_left(server, player, player->lvl->lvl, to_send);
    }
    my_strcat(to_send, "]\n", strlen(to_send));
    dprintf(player->fd, to_send);
    destroy_action(player->act);
}

void get_tile_look(s_serv *server, char *tmp, int x, int y)
{
    char stock[12];
    int p_cnt = 0;

    for (int i = 0 ; i < server->map[y][x]->players ; i++)
        p_cnt++;
    if (p_cnt) {
        my_strcat(tmp, "player x", strlen(tmp));
        sprintf(stock, "%d", p_cnt);
        my_strcat(tmp, stock, strlen(tmp));
        my_strcat(tmp, " ", strlen(tmp));
    }
    for (int i = 0 ; i < 7 ; i++)
        if (server->map[y][x]->stock[i]) {
            my_strcat(tmp, object[i], strlen(tmp));
            my_strcat(tmp, " ", strlen(tmp));
            my_strcat(tmp, "x", strlen(tmp));
            sprintf(stock, "%d", server->map[y][x]->stock[i]);
            my_strcat(tmp, stock, strlen(tmp));
            my_strcat(tmp, " ", strlen(tmp));
        }
}
