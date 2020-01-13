/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "cmd_func.h"

void player_action(s_serv *serv, s_player *player)
{
    if ((time(NULL) - player->act->start[0]) > player->act->time[0]) {
        cmd_func[player->act->acts[0]](serv, player);
    }
}

static int check_life(s_serv *serv, s_player *player, int time)
{
    if ((time - player->inv->last_food) >= REFRESH_CALC(126, serv->freq)) {
        player->inv->last_food = time;
        player->inv->stock[0]--;
        if (player->inv->stock[0] <= 0) {
            player_die(serv, player);
            return 1;
        }
    }
    return 0;
}

void check_egg(s_serv *serv, s_player *player)
{
    int tmp_time = time(NULL);

    if ((tmp_time - player->egg_time) >= REFRESH_CALC(126, serv->freq)) {
        player->x = rand() % 3 + 1;
        player->y = rand() % 3 + 1;
        player->is_egg = 0;
    }
}

static void in_loop(s_serv *serv, int i, int j, int tmp)
{
    int bool;

    if (serv->entry[i]->player[j]->is_egg == 1) {
        check_egg(serv, serv->entry[i]->player[j]);
    }
    if (serv->entry[i]->player[j]->active == 1 &&
        serv->entry[i]->player[j]->act->many >= 0) {
        bool = check_life(serv, serv->entry[i]->player[j], tmp);
        if (bool == 0) {
            player_action(serv, serv->entry[i]->player[j]);
        }
    } else if (serv->entry[i]->player[j]->active == 1)
    check_life(serv, serv->entry[i]->player[j], tmp);
}

void check_players(s_serv *serv, struct timeval *select_clock)
{
    int tmp;

    select_clock->tv_sec = 0;
    for (int i = 0; serv->entry[i] != NULL; i++) {
        tmp = time(NULL);
        for (int j = 0; serv->entry[i]->player[j] != NULL; j++) {
            in_loop(serv, i, j, tmp);
        }
    }
}
