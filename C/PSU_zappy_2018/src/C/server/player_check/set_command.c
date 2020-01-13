/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "actions.h"

void destroy_action(s_action *act)
{
    if (act->act_str[0] != NULL)
        free(act->act_str[0]);
    for (int i = 0; i != 10; i++) {
        if (act->acts[i + 1] != -1) {
            act->acts[i] = act->acts[i + 1];
            act->time[i] = act->time[i + 1];
            act->start[i] = act->start[i + 1];
        } else {
            act->acts[i] = -1;
            act->time[i] = -1;
            act->start[i] = -1;
        }
    }
    act->many--;
}

static char *get_first(char *str)
{
    char *to_ret = strdup(str);

    for (int i = 0; to_ret[i] != '\0'; i++)
        if (to_ret[i] == ' ' || to_ret[i] == '\n') {
            to_ret[i] = '\0';
            return to_ret;
        }
    return to_ret;
}

int is_command(char *str)
{
    char *tmp = get_first(str);

    for (int i = 0; cmd[i] != NULL; i++) {
        if (strcmp(tmp, cmd[i]) == 0) {
            free(tmp);
            return i;
        }
    }
    free(tmp);
    return 12;
}

static char *handle_buff(char *buff)
{
    char *to_ret;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ' ' && buff[i + 1]) {
            to_ret = strdup(&buff[i + 1]);
            return to_ret;
        }
    }
    return NULL;
}

void set_action(s_serv *serv, s_player *player, int command, char *buff)
{
    const int cmd_lenght[13] = {7, 7, 7, 7, 1, 7, 0, 42, 7, 7, 7, 300, 0};

    player->act->many++;
    player->act->acts[player->act->many] = command;
    player->act->time[player->act->many] = REFRESH_CALC(cmd_lenght[command],
        serv->freq);
    player->act->act_str[player->act->many] = handle_buff(buff);
    player->act->start[player->act->many] = time(NULL);
    player->act->acts[player->act->many + 1] = -1;
    player->act->time[player->act->many + 1] = -1;
    player->act->start[player->act->many + 1] = -1;
}
