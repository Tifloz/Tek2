/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include "network.h"
#include "client.h"

int add_sprite(assets_t *assets, enum SPRITE_NAME name, char *path, bool enabled
)
{
    assets->textures[name] = sfTexture_createFromFile(path, NULL);
    if (!assets->textures[name])
        return (EXIT_FAILURE);
    assets->sprites[name] = sfSprite_create();
    if (!assets->sprites[name])
        return (EXIT_FAILURE);
    sfSprite_setTexture(assets->sprites[name], assets->textures[name], sfTrue);
    assets->active[name] = enabled;
    return (EXIT_SUCCESS);
}

void destroy_assets(game_t *game)
{
    for (int i = 0; i < SPRITES; i++) {
        if (game->assets.sprites[i] == NULL)
            return;
        sfSprite_destroy(game->assets.sprites[i]);
        sfTexture_destroy(game->assets.textures[i]);
    }
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->window);
}