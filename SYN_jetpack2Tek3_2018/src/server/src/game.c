/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** game.c
*/

#include <stdlib.h>
#include "server.h"

void check_winner(s_client *c)
{
    if (c[0].winner == 1) {
        send_message(c[0].fd, "FINISH %d\n", c[0].id);
        send_message(c[1].fd, "FINISH %d\n", c[0].id);
    } else if (c[1].winner == 1) {
        send_message(c[0].fd, "FINISH %d\n", c[1].id);
        send_message(c[1].fd, "FINISH %d\n", c[1].id);
    } else {
        send_message(c[0].fd, "FINISH -1\n");
        send_message(c[1].fd, "FINISH -1\n");
    }
}

void determine_position(s_client *c, s_args *a)
{
    (void)c;
    (void)a;
}

void game_supervisor(s_client *c, s_server *s, s_args *a)
{
    (void)s;
    check_winner(c);
    determine_position(c, a);
}