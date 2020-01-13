/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

static void reset_inv(s_player *player)
{
    player->inv->stock[0] = 10;
    for (int i = 1; i != 6; i++) {
        player->inv->stock[i] = 10;
    }
    player->inv->food = 10;
    player->inv->last_food = 0;
    player->inv->linemate = 0;
    player->inv->deuramere = 0;
    player->inv->sibur = 0;
    player->inv->mendiane = 0;
    player->inv->phiras = 0;
    player->inv->thystame = 0;
}

static void reset_act(s_player *player)
{
    player->act->many = -1;
    for (int i = 0; i != 11; i++) {
        player->act->acts[i] = -1;
        player->act->time[i] = -1;
        player->act->start[i] = -1;
    }
}

void reset_values(s_serv *serv, s_player *player)
{
    player->active = 0;
    player->x = serv->x + 1;
    player->y = serv->y + 1;
    player->lvl->lvl = 1;
    player->lvl->dir = rand() % 3 + 1;
    player->id = 0;
    serv->last_player[player->team] = find_active(serv,
        serv->entry[player->team], player->team);
    player->team = -1;
    player->fd = -1;
}

void player_die(s_serv *serv, s_player *player)
{
    remove_player_from(serv->map[player->y][player->x],
        player, get_player_pos_by_fd(serv, player->fd, player->team));

    write(player->fd, "dead\n", 5);
    close(player->fd);
    if (serv->graph->active == 1) {
        dprintf(serv->graph->fd, "pdi %d %d\n", player->team,
        get_player_pos_by_fd(serv, player->fd, player->team));
    }
    FD_CLR(player->fd, &serv->active_fd_set);
    reset_values(serv, player);
    reset_inv(player);
    reset_act(player);
}
