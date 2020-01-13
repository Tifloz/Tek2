/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_JETPACK2TEK3_2018_CLIENT_H
#define SYN_JETPACK2TEK3_2018_CLIENT_H

#include <SFML/Graphics.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define SPRITES 3
#define HEIGHT        ((float)1080 / network->height)
#define WIDTH        ((float)1920 / network->width)
#define IS_COIN    (network->map[i[0]][i[1]] == 'c')
#define IS_ELEC    (network->map[i[0]][i[1]] == 'e')


enum SPRITE_NAME {
    BACKGROUND,
    ELEC,
    COIN
};

typedef struct assets_s {
    sfSprite *sprites[SPRITES];
    sfTexture *textures[SPRITES];
    int active[SPRITES];
    sfText *gui[3];
} assets_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int coin;
    int id;
    float x;
    float y;
} player_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    assets_t assets;
    player_t players[2];
    sfClock *clock;
    sfFont *font;
} game_t;

int add_sprite(assets_t *assets, enum SPRITE_NAME name, char *path, bool enabled
);

int init_assets(assets_t *assets);

void destroy_assets(game_t *game);

int init_window(game_t *game);

int init_players(game_t *game);

void drawer(game_t *game);

char *my_clean_str(char *str);

char **my_str_to_wordarray(char *str, char c);

#endif
