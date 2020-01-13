/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

s_map *get_tile_x(void)
{
    s_map *to_ret = malloc(sizeof(s_map));

    to_ret->stock[0] = rand() % 15 + 5;
    for (int i = 1; i != 7; i++) {
        to_ret->stock[i] = rand() % 4;
    }
    to_ret->p_pos_team = malloc(sizeof(int) * (P_PER_MAP + 1));
    to_ret->p_pos = malloc(sizeof(int) * (P_PER_MAP + 1));
    to_ret->mallocd = 1;
    to_ret->players = 0;
    for (int i = 0; i != (P_PER_MAP + 1); i++) {
        to_ret->p_pos_team[i] = -1;
        to_ret->p_pos[i] = -1;
    }
    to_ret->next_free_pos = 0;
    return to_ret;
}

s_map **get_tile_y(int x)
{
    s_map **to_ret = malloc(sizeof(s_map *) * (x + 2));

    to_ret[x] = NULL;
    for (int i = 0; i != x + 1; i++) {
        to_ret[i] = get_tile_x();
        to_ret[i + 1] = NULL;
    }
    return to_ret;
}

void get_map(int x, int y, s_serv *server)
{
    srand(time(0));
    server->y = y;
    server->x = x;
    server->map = malloc(sizeof(s_map **) * ((y + 2) * 2));
    server->map[y] = NULL;
    for (int i = 0; i != y; i++) {
        server->map[i] = get_tile_y(x);
        server->map[i + 1] = NULL;
    }
}
