/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void free_parse(s_parse *parse)
{
    for (int i = 0; parse->teams[i] != NULL; i++) {
        free(parse->teams[i]);
    }
    free(parse->teams);
}

static void free_players(s_player **players, int max)
{
    for (int i = 0; i != max; i++) {
        free(players[i]->lvl);
        free(players[i]->act);
        free(players[i]->inv);
        free(players[i]);
    }
    free(players);
}

void free_point(s_team *team, int max)
{
    free(team->name);
    team->prev = NULL;
    free_players(team->player, max);
}

void free_server(s_serv *serv)
{
    free(serv->graph);
    for (int i = 0; i != serv->y; i++) {
        for (int j = 0; j != serv->x - 1; j++) {
            free(serv->map[i][j]->p_pos_team);
            free(serv->map[i][j]->p_pos);
            free(serv->map[i][j]);
        }
        free(serv->map[i]);
    }
    free(serv->map);
    free(serv->socket);
    free(serv->last_id_team);
    for (; serv->team != NULL; serv->team = serv->team->next) {
        free_point(serv->team, serv->max_per_team);
    }
    for (int i = 0; i != serv->nb_team; i++)
        free(serv->entry[i]);
    free(serv->entry);
}
