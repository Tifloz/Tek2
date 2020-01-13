/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

char *get_team_names_graph(char **str, int nb)
{
    char *to_ret = malloc(sizeof(char) * 4096);

    to_ret[0] = '\0';
    for (int i = 0; i != nb; i++) {
        to_ret = my_strcat(to_ret, str[i], strlen(to_ret));
        to_ret = my_strcat(to_ret, " ", strlen(to_ret));
    }
    return to_ret;
}

void print_player(s_serv *server, s_player *player, int i, int j)
{
    dprintf(server->graph->fd,
    "jpp %d %d %d %d %d %d %d %d %d %d %d %d %d\n",  i, j, player->y, player->x,
    player->lvl->lvl, player->lvl->dir, player->inv->stock[0],
    player->inv->stock[1], player->inv->stock[2], player->inv->stock[3],
    player->inv->stock[4], player->inv->stock[5], player->inv->stock[6]);
}

void print_players(s_serv *server)
{
    for (int i = 0; server->entry[i] != NULL; i++) {
        for (int j = 0; server->entry[i]->player[j] != NULL; j++) {
            if (server->entry[i]->player[j]->active == 1)
                print_player(server, server->entry[i]->player[j], i, j);
        }
    }
}
