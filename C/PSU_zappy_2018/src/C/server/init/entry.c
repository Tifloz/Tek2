/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

static void get_first_entry(s_serv *serv)
{
    serv->entry[0] = malloc(sizeof(s_team *) * (1 + 1));
    serv->entry[0] = serv->team;
    serv->entry[1] = NULL;
    return;
}

static void get_length_ptr(s_serv *serv)
{
    int i = 0;

    for (s_team *tmp = serv->team; tmp != NULL; tmp = tmp->next)
        i++;
    serv->nb_team = i;
}

static void get_last_player(s_serv *serv)
{
    serv->last_player = malloc(sizeof(int) * (serv->nb_team + 2));
    for (int i = 0; i != serv->nb_team; i++)
        serv->last_player[i] = 0;
    serv->last_player[serv->nb_team + 1] = -1;
}

static void get_entry_team_for_norm(s_serv *serv, int i)
{
    for (i = 0; i != serv->nb_team; i++) {
        serv->names[i] = strdup(serv->entry[i]->name);
        serv->names[i + 1] = NULL;
    }
    serv->last_id_team = malloc(sizeof(int) * (serv->nb_team + 1));
    for (int i = 0; i != serv->nb_team; i++) {
        serv->last_id_team = 0;
    }
    serv->more_player = malloc(sizeof(int) * (serv->nb_team + 1));
    for (int i = 0; i != (serv->nb_team + 1); i++) {
        serv->more_player[i] = 0;
    }
    get_last_player(serv);
}

void get_entry_team(s_serv *serv)
{
    int i = 0;

    serv->all = 0;
    get_length_ptr(serv);
    if (serv->nb_team == 0) {
        get_first_entry(serv);
        return;
    }
    serv->entry = malloc(sizeof(s_team *) * (serv->nb_team + 1));
    for (s_team *tmp = serv->team; tmp != NULL; tmp = tmp->next) {
        serv->entry[i] = tmp;
        i++;
    }
    serv->entry[i] = NULL;
    serv->names = malloc(sizeof(char *) * (serv->nb_team + 1));
    get_entry_team_for_norm(serv, i);
}
