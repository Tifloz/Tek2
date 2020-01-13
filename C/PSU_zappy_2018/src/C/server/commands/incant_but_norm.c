/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

int check_tile(s_map *map, int *stock)
{
    for (int i = 1; i != 7; i++) {
        if (stock[i - 1] != map->stock[i])
            return 0;
    }
    return 1;
}

void get_incant(s_incant *incant, s_serv *server, s_player *player)
{
    incant->tmp_nb_player = 0;
    incant->to_send = malloc(sizeof(int) *
    (server->map[player->y][player->x]->players + 2) + 1000);
    incant->tmp_pt = malloc(sizeof(int) *
    (server->map[player->y][player->x]->players + 2) + 1000);
    incant->tmp_p = malloc(sizeof(int) *
    (server->map[player->y][player->x]->players + 2) + 1000);
    incant->max = server-> map[player->y][player->x]->mallocd * P_PER_MAP;
}

void norm_norm_norm(s_player *player, s_incant *incant)
{
    dprintf(player->fd, "ko\n");
    destroy_action(player->act);
    free(incant->to_send);
    free(incant->tmp_pt);
    free(incant->tmp_p);
    return;
}

void free_incant(s_incant *incant)
{
    free(incant->to_send);
    free(incant->tmp_pt);
    free(incant->tmp_p);
}
