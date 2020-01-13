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

void check_case(network_t *network, int i[2], sfVector2f *rect)
{
    if (IS_COIN) {
        sfSprite_setPosition(network->game.assets.sprites[COIN], *rect);
        sfRenderWindow_drawSprite(network->game.window,
            network->game.assets.sprites[COIN], NULL);
    } else if (IS_ELEC) {
        sfSprite_setPosition(network->game.assets.sprites[ELEC], *rect);
        sfRenderWindow_drawSprite(network->game.window,
            network->game.assets.sprites[ELEC], NULL);
    }
}

void draw_map(network_t *network)
{
    int i[2];
    sfVector2f rect;

    i[0] = 0;
    while (i[0] < network->height && network->map) {
        i[1] = 0;
        while (i[1] < network->width) {
            rect.x = i[1] * WIDTH;
            rect.y = i[0] * HEIGHT;
            check_case(network, i, &rect);
            i[1]++;
        }
        i[0]++;
    }
}

void draw_score(network_t *network)
{
    sfVector2f pos = {1650, 100};
    char *coins = malloc(sizeof(char) * strlen("Enemy coins : XXX") + 1);

    if (!coins)
        return;
    sprintf(coins, "Your coins = %d", network->game.players[0].coin);
    sfText_setString(network->game.assets.gui[1], coins);
    sfText_setPosition(network->game.assets.gui[1], pos);
    pos.y += 100;
    pos.x -= 30;
    sprintf(coins, "Enemy coins = %d", network->game.players[1].coin);
    sfText_setString(network->game.assets.gui[2], coins);
    sfText_setPosition(network->game.assets.gui[2], pos);
    free(coins);
}

void draw_text(network_t *network)
{
    char *str = malloc(
        sizeof(char) * strlen("Connnected to XXX.XXX.XXX.XXX") + 1);
    sfVector2f pos = {1650, 1};

    if (!str)
        return;
    draw_map(network);
    if (network->connected) {
        sprintf(str, "Connected to %s", network->ip);
        sfText_setString(network->game.assets.gui[0], str);
        sfText_setColor(network->game.assets.gui[0], sfGreen);
        draw_score(network);
    } else {
        sfText_setString(network->game.assets.gui[0], "Disconnected");
        sfText_setPosition(network->game.assets.gui[0], pos);
        sfText_setColor(network->game.assets.gui[0], sfRed);
    }
    for (int i = 0; i < 3; ++i)
        sfRenderWindow_drawText(network->game.window,
            network->game.assets.gui[i], NULL);
    free(str);
}

void drawer(game_t *game)
{
    sfRenderWindow_clear(game->window, sfRed);
    for (int i = 0; i < SPRITES; i++) {
        if (game->assets.sprites[i] == NULL)
            return;
        if (game->assets.active[i] == 1)
            sfRenderWindow_drawSprite(game->window, game->assets.sprites[i],
                NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->players[1].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->players[0].sprite, NULL);
    sfSprite_setTextureRect(game->players[0].sprite, game->players[0].rect);
    sfSprite_setTextureRect(game->players[1].sprite, game->players[1].rect);
}