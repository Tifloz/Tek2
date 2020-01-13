/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void player_move_to(s_serv *server, s_player *player, int y, int x)
{
    int p_pos = get_player_pos_by_fd(server, player->fd, player->team);
    int tmp_x = player->x - x;
    int tmp_y = player->y - y;

    if (tmp_x <= -1)
        tmp_x = server->x - 1;
    if (tmp_y <= -1)
        tmp_y = server->y - 1;
    if (tmp_y >= server->y)
        tmp_y = 0;
    if (tmp_x >= server->x)
        tmp_x = 0;
    remove_player_from(server->map[tmp_y][tmp_x], player, p_pos);
    add_player_to(server, server->map[player->y][player->x], player, p_pos);
}

void remove_player_from(s_map *map, s_player *player, int p_pos)
{
    int max = map->mallocd * P_PER_MAP;

    for (int i = 0; i != max; i++) {
        if (i >= max)
            return;
        if (map->p_pos[i] == -1)
            continue;
        if (map->p_pos[i] == p_pos && map->p_pos_team[i] == player->team) {
            map->p_pos[i] = -1;
            map->p_pos_team[i] = -1;
            map->players--;
            actualise_free_pos(map);
            return;
        }
    }
}

void add_player_to(s_serv *server, s_map *map, s_player *player,
    __attribute__((unused))int p_pos)
{
    map->players++;
    if (map->players >= (map->mallocd * P_PER_MAP))
        get_bigger_map(map);
    map->p_pos[map->next_free_pos] = get_player_pos_by_fd(server,
        player->fd, player->team);
    map->p_pos_team[map->next_free_pos] = player->team;
    actualise_free_pos(map);
}
