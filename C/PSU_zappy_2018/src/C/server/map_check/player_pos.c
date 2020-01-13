/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void actualise_free_pos(s_map *map)
{
    for (int i = 0; i != ((map->mallocd) * P_PER_MAP); i++) {
        if (map->p_pos[i] == -1) {
            map->next_free_pos = i;
            return;
        }
    }
}

int get_player_pos_by_fd(s_serv *serv, int fd, int team)
{
    for (int i = 0; i != (serv->max_per_team + serv->more_player[team]); i++) {
        if (serv->entry[team]->player[i]->active == 0)
            continue;
        if (serv->entry[team]->player[i]->active == 1 &&
            serv->entry[team]->player[i]->fd == fd)
            return i;
    }
    exit(98);
}
