/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include "network.h"
#include "client.h"
#include "network.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void anim_player(game_t *game, int *stop)
{
    for (int player = 0; player < 2; player++) {
        if (game->players[player].rect.left >= 243) {
            game->players[player].rect.left = 0;
            *stop = *stop + 1;
        } else {
            game->players[player].rect.left += 81;
            *stop = *stop + 1;
        }
    }
}

void move_player(network_t *network)
{
    sfVector2f pos;

    for (int i = 0; i < 2; ++i) {
        pos.x = network->game.players[i].x * WIDTH;
        pos.y = network->game.players[i].y * HEIGHT;
        sfSprite_setPosition(network->game.players[i].sprite, pos);
    }
}

void my_clock(network_t *network)
{
    network->game.clock = sfClock_create();
    int stop = 0;

    while (stop < 1) {
        if ((sfClock_getElapsedTime(network->game.clock).microseconds /
            1000000.0) > 0.10f) {
            anim_player(&network->game, &stop);
            move_player(network);
            sfClock_restart(network->game.clock);
        }
    }
}

void event_manager(network_t *net)
{
    if (net->game.event.type == sfEvtClosed ||
        net->game.event.key.code == sfKeyEscape || net->endgame) {
        sfRenderWindow_close(net->game.window);
        net->endgame = true;
    } else if (net->game.event.type == sfEvtKeyPressed &&
        net->game.event.key.code == sfKeySpace && net->connected)
        dprintf(net->sock_fd, "FIRE 1\n");
    else if (net->game.event.type == sfEvtKeyReleased &&
        net->game.event.key.code == sfKeySpace && net->connected)
        dprintf(net->sock_fd, "FIRE 0\n");
}

int run(network_t *net)
{
    if (init_window(&net->game) || init_assets(&net->game.assets) ||
        init_players(&net->game) || init_texts(net))
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(net->game.window)) {
        while (sfRenderWindow_pollEvent(net->game.window, &net->game.event)) {
            event_manager(net);
        }
        drawer(&net->game);
        draw_text(net);
        my_clock(net);
        sfRenderWindow_display(net->game.window);
    }
    destroy_assets(&net->game);
    return (net->error);
}