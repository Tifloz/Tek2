/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "object.h"

char *my_strcat(char *str1, const char *str2, int n)
{
    for (int i = 0; str2[i] != '\0'; i++) {
        str1[n + i] = str2[i];
        str1[n + i + 1] = '\0';
    }
    return str1;
}

void inventory(__attribute__((unused))s_serv *server, s_player *player)
{
    char *tmp = malloc(sizeof(char) * (INV_SIZE * 2));
    char tmp_number[10];

    tmp[0] = '[';
    tmp[1] = '\0';
    tmp_number[0] = '\0';
    for (int i = 0; i != OBJ_SIZE; i++) {
        tmp = my_strcat(tmp, object[i], strlen(tmp));
        tmp = my_strcat(tmp, " ", strlen(tmp));
        sprintf(tmp_number, "%d", player->inv->stock[i]);
        tmp = my_strcat(tmp, tmp_number, strlen(tmp));
        if (i + 1 != OBJ_SIZE)
            tmp = my_strcat(tmp, ", ", strlen(tmp));
    }
    tmp = my_strcat(tmp, "]", strlen(tmp));
    tmp = my_strcat(tmp, "\n", strlen(tmp));
    dprintf(player->fd, tmp);
    free(tmp);
    destroy_action(player->act);
}
