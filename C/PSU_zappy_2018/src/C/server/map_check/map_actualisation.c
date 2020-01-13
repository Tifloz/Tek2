/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void get_bigger_map(s_map *to_bigger)
{
    int *first = malloc(sizeof(int) * ((to_bigger->mallocd + 2) * P_PER_MAP));
    int *second = malloc(sizeof(int) * ((to_bigger->mallocd + 2) * P_PER_MAP));
    int last_size = (to_bigger->mallocd) * P_PER_MAP;

    for (int i = 0; i != ((to_bigger->mallocd + 2) * P_PER_MAP); i++) {
        if (i <= last_size) {
            first[i] = to_bigger->p_pos_team[i];
            second[i] = to_bigger->p_pos[i];
        } else {
            first[i] = -1;
            second[i] = -1;
        }
    }
    free(to_bigger->p_pos_team);
    free(to_bigger->p_pos);
    to_bigger->mallocd++;
    to_bigger->p_pos_team = first;
    to_bigger->p_pos = second;
}

void player_first_pos(s_serv *server, s_map *map, s_player *player)
{
    map->players++;
    map->p_pos_team[map->next_free_pos] = player->team;
    map->p_pos[map->next_free_pos] = get_player_pos_by_fd(server,
        player->fd, player->team);
    actualise_free_pos(map);
}

void first_tile(s_serv *server, s_map ***map, s_player *player)
{
    if (map[player->y][player->x]->players >=
        (map[player->y][player->x]->mallocd * P_PER_MAP))
        get_bigger_map(map[player->y][player->x]);
    player_first_pos(server, map[player->y][player->x], player);
}

void actualize_map(s_serv *server, struct timeval *select_clock)
{
    check_players(server, select_clock);
}

void player_move_on_map(s_serv *server, s_player *player, int dir)
{
    if (dir == 0) {
        player->x--;
        if (player->x < 0)
            player->x = (server->x - 1);
        player_move_to(server, player, 0, -1);
    } else if (dir == 1) {
        player->y++;
        if (player->y >= (server->y))
            player->y = 0;
        player_move_to(server, player, 1, 0);
    } else if (dir == 2) {
        player->x++;
        if (player->x >= (server->x))
            player->x = 0;
        player_move_to(server, player, 0, 1);
    } else if (dir == 3) {
        player->y--;
        if (player->y < 0)
            player->y = (server->y - 1);
        player_move_to(server, player, -1, 0);
    }
}
