/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

static s_inv *set_inventory(void)
{
    s_inv *to_ret = malloc(sizeof(s_inv));
    to_ret->stock[0] = 10;
    to_ret->stock[1] = 0;
    to_ret->stock[2] = 0;
    to_ret->stock[3] = 0;
    to_ret->stock[4] = 0;
    to_ret->stock[5] = 0;
    to_ret->stock[6] = 0;
    to_ret->last_food = 0;
    return to_ret;
}

static s_lvl *set_level(void)
{
    s_lvl *to_ret = malloc(sizeof(s_lvl));

    to_ret->lvl = 1;
    to_ret->dir = rand() % 3 + 1;
    return to_ret;
}

s_player *get_player(int maxy, int maxx)
{
    s_player *to_ret = malloc(sizeof(s_player));

    to_ret->id = 0;
    to_ret->x = maxy + 1;
    to_ret->y = maxx + 1;
    to_ret->active = 0;
    to_ret->act = malloc(sizeof(s_action));
    to_ret->act->many = -1;
    to_ret->inv = set_inventory();
    to_ret->lvl = set_level();
    to_ret->is_egg = 0;
    to_ret->egg_time = 0;
    for (int i = 0; i != 11; i++) {
        to_ret->act->acts[i] = -1;
        to_ret->act->time[i] = -1;
        to_ret->act->start[i] = -1;
    }
    return to_ret;
}

static s_player **malloc_player(int max, int maxy, int maxx)
{
    s_player **to_ret = malloc(sizeof(s_player *) * (max + 1));

    for (int i = 0; i != max; i++) {
        if ((max - i) >= 5) {
            to_ret[i] = get_player(maxy, maxx);
            to_ret[i + 1] = get_player(maxy, maxx);
            to_ret[i + 2] = get_player(maxy, maxx);
            to_ret[i + 3] = get_player(maxy, maxx);
            to_ret[i + 4] = get_player(maxy, maxx);
            to_ret[i + 5] = NULL;
            i += 4;
        } else {
            to_ret[i] = get_player(maxy, maxx);
            to_ret[i + 1] = NULL;
        }
    }
    return to_ret;
}

s_team *init_teams(char **teams, int max_player, int maxy, int maxx)
{
    s_team *to_ret = malloc(sizeof(s_team)), *tmp;

    to_ret->player = malloc_player(max_player, maxy, maxx);
    to_ret->name = strdup(teams[0]);
    to_ret->prev = NULL;
    to_ret->next = NULL;
    tmp = to_ret;
    if (!teams[1])
        return to_ret;
    for (int i  = 1; teams[i] != NULL; i++) {
        s_team *new = malloc(sizeof(s_team));
        new->name = strdup(teams[i]);
        new->player = malloc_player(max_player, maxy, maxx);
        new->prev = tmp;
        new->next = NULL;
        tmp->next = new;
        tmp = tmp->next;
    }
    return to_ret;
}
