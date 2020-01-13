/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void print_tile(s_serv *server, s_map *map, int x, int y)
{
    dprintf(server->graph->fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    map->stock[0], map->stock[1], map->stock[2], map->stock[3], map->stock[4],
    map->stock[5], map->stock[6]);
}

void print_tiles(s_serv *serv)
{
    for (int i = 0; i != (serv->y); i++) {
        for (int j = 0; j != (serv->x); j++) {
            print_tile(serv, serv->map[i][j], i, j);
        }
    }
}

void send_data_to_graph(s_serv *server, int fd)
{
    char *tmp;

    dprintf(fd, "start init\n");
    dprintf(fd, "tnb %d\n", server->nb_team);
    tmp = get_team_names_graph(server->names, server->nb_team);
    dprintf(fd, "tna %s\n", tmp);
    print_players(server);
    free(tmp);
    dprintf(fd, "msz %d %d\n", server->y, server->x);
    print_tiles(server);
    dprintf(fd, "end init\n");
}
