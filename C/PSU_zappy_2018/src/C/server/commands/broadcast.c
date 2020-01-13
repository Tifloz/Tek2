/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include <math.h>
#include "include.h"
#include "struct.h"

static double modulo(double nb, int mod)
{
    while (nb >= mod)
        nb -= mod;
    while (nb < 0)
        nb += mod;
    return nb;
}

int comput_angle(int xp, int yp, int xt, int yt)
{
    double y = yt - yp;
    double x = xt - xp;
    double angle = modulo(atan(y / x) / M_PI * 180, 90);

    printf("tan = %f  ", angle);
    if (angle < 22.5)
        return 0;
    else if (angle > 67.5)
        return 2;
    return 1;
}

void send_broadcast(s_player *player, s_player *target)
{
    char tmp[4096] = "BROADCAST \0";
    int angle = comput_angle(player->x, player->y, target->x, target->y);
    char cells[4][3][2] = {{"1\0", "2\0", "3\0"}, {"5\0", "4\0", "3\0"},
                            {"5\0", "6\0", "7\0"}, {"1\0", "8\0", "7\0"}};

    memset(tmp + strlen(tmp), 0, 4096 - strlen(tmp));
    if (player->x < target->x) {
        if (player->y < target->y)
            my_strcat(tmp, cells[2][angle], strlen(tmp));
        else
            my_strcat(tmp, cells[1][angle], strlen(tmp));
    } else {
        if (player->y < target->y)
            my_strcat(tmp, cells[3][angle], strlen(tmp));
        else
            my_strcat(tmp, cells[0][angle], strlen(tmp));
    }
    my_strcat(tmp, " ", strlen(tmp));
    my_strcat(tmp, player->act->act_str[0], strlen(tmp));
    my_strcat(tmp, "\n", strlen(tmp));
    dprintf(target->fd, tmp);
}

void broadcast(s_serv *server, s_player *player)
{
    for (int i = 0 ; i < server->nb_team ; i++)
        for (int j = 0 ; server->entry[i]->player[j] ; j++)
            if (server->entry[i]->player[j]->active &&
                player->id != server->entry[i]->player[j]->id)
                send_broadcast(player, server->entry[i]->player[j]);
    dprintf(player->fd, "ok\n");
    if (server->graph->active == 1) {
        dprintf(server->graph->fd, "pbc %d %d %s", player->y,
        player->x, player->act->act_str[0]);
    }
    destroy_action(player->act);
}
