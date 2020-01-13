/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include "network.h"
#include "client.h"
#include <string.h>

int init_assets(assets_t *assets)
{
    if (add_sprite(assets, BACKGROUND, "./assets/full.png", true) ||
        add_sprite(assets, ELEC, "./assets/elec.png", false) ||
        add_sprite(assets, COIN, "./assets/coins.png", false))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int init_texts(network_t *network)
{
    sfVector2f pos = {1500, 1};

    network->game.font = sfFont_createFromFile("./assets/font.otf");
    if (!network->game.font)
        return (EXIT_FAILURE);
    for (int i = 0; i < 3; i++) {
        network->game.assets.gui[i] = sfText_create();
        sfText_setFont(network->game.assets.gui[i], network->game.font);
        sfText_setCharacterSize(network->game.assets.gui[i], 50);
    }
    sfText_setColor(network->game.assets.gui[1], sfBlue);
    sfText_setColor(network->game.assets.gui[2], sfYellow);
    sfText_setPosition(network->game.assets.gui[0], pos);

    return (EXIT_SUCCESS);
}

int init_window(game_t *game)
{
    size_t nb;
    const sfVideoMode *mode = sfVideoMode_getFullscreenModes(&nb);

    game->window = sfRenderWindow_create(mode[0], "Jetpack2Tek3", sfFullscreen,
        NULL);
    if (!game->window)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    return (EXIT_SUCCESS);
}

void init_player_rect(player_t *player)
{
    player->rect.width = 81;
    player->rect.height = 78;
    player->rect.left = 0;
    player->rect.top = 0;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

int init_players(game_t *game)
{
    game->players[0].texture = sfTexture_createFromFile("./assets/player.png",
        NULL);
    game->players[0].sprite = sfSprite_create();
    if (!game->players[0].texture || !game->players[0].sprite)
        return (EXIT_FAILURE);
    sfSprite_setTexture(game->players[0].sprite, game->players[0].texture,
        sfTrue);
    init_player_rect(&game->players[0]);
    game->players[1].texture = sfTexture_createFromFile("./assets/player2.png",
        NULL);
    game->players[1].sprite = sfSprite_create();
    if (!game->players[1].texture || !game->players[1].sprite)
        return (EXIT_FAILURE);
    sfSprite_setTexture(game->players[1].sprite, game->players[1].texture,
        sfTrue);
    init_player_rect(&game->players[1]);
    return (EXIT_SUCCESS);
}