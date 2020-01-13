/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "response.h"

void add_egg_at(s_serv *serv, s_player *player)
{
    serv->more_player[player->team]++;
    serv->entry[player->team]->player = (s_player**)realloc(serv->entry
        [player->team]->player, (sizeof(s_player **) * (serv->max_per_team
            + serv->more_player[player->team] + 2)));
    serv->last_player[player->team] = serv->max_per_team
    + serv->more_player[player->team] - 1;
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team] - 1] = get_player(serv->y, serv->x);
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team]] = NULL;
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team] - 1]->x = player->x;
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team] - 1]->y = player->y;
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team] - 1]->is_egg = 1;
    serv->entry[player->team]->player[serv->max_per_team
    + serv->more_player[player->team] - 1]->egg_time = time(NULL);
}

void fork_p(s_serv *server, s_player *player)
{
    add_egg_at(server, player);
    if (server->graph->active == 1) {
        dprintf(server->graph->fd, "egg %d %d %d", player->team,
        player->y, player->x);
    }
    dprintf(player->fd, response[player->act->acts[0]]);
    destroy_action(player->act);

}
