/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

int match_new(char *buff, char **teams)
{
    for (int i = 0; teams[i] != NULL; i++)
        if (strcmp(buff, teams[i]) == 0) {
            return i;
        }
    return -1;
}

int find_active(s_serv *serv, s_team *team, int p_pt)
{

    int i = 0;
    for (i = 0; i != (serv->max_per_team + serv->more_player[p_pt] - 1); i++) {
        if (team->player[i]->active == 0)
            return i;
    }
    return serv->max_per_team + serv->more_player[p_pt];
}

void new_player_random_pos(s_serv *server, s_player *player)
{
    player->x = rand() % server->x;
    player->y = rand() % server->y;
}
