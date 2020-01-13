/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void error(__attribute__((unused))s_serv *serv, s_player *player)
{
    dprintf(player->fd, "ko\n");
    destroy_action(player->act);
}
