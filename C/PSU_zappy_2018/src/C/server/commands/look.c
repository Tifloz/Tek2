/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
//#include "object.h"

static int modulo(int nb, int mod)
{
    while (nb >= mod)
        nb -= mod;
    while (nb < 0)
        nb += mod;
    return nb;
}

void look_up(s_serv *server, s_player *player, int lvl, char *to_send)
{
    for (int y = 1 ; y < lvl ; y++)
        for (int x = -y ; x <= y ; x++) {
            my_strcat(to_send, ", ", strlen(to_send));
            get_tile_look(server, to_send, modulo((player->x + x), server->x),
                modulo((player->y + y), server->y));
        }
}

void look_down(s_serv *server, s_player *player, int lvl, char *to_send)
{
    for (int y = 1 ; y < lvl ; y++)
        for (int x = -y ; x <= y ; x++) {
            my_strcat(to_send, ", ", strlen(to_send));
            get_tile_look(server, to_send, modulo((player->x + x), server->x),
                modulo((player->y - y), server->y));
        }
}

void look_right(s_serv *server, s_player *player, int lvl, char *to_send)
{
    for (int x = 1 ; x < lvl ; x++)
        for (int y = -x ; y <= x ; y++) {
            my_strcat(to_send, ", ", strlen(to_send));
            get_tile_look(server, to_send, modulo((player->x + x), server->x),
                modulo((player->y + y), server->y));
        }
}

void look_left(s_serv *server, s_player *player, int lvl, char *to_send)
{
    for (int x = 1 ; x < lvl ; x++)
        for (int y = -x ; y <= x ; y++) {
            my_strcat(to_send, ", ", strlen(to_send));
            get_tile_look(server, to_send, modulo((player->x - x), server->x),
                modulo((player->y + y), server->y));
        }
}
