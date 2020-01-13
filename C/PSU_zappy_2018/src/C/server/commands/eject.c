/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "dir.h"
//#include "response.h"

void eject_player(s_serv *server, s_player *player)
{
    player_move_on_map(server, player, player->lvl->dir);
    dprintf(player->fd, "eject :%s\n", dir[player->lvl->dir]);
}

void no_more_than_2_embranchements(s_serv *server, s_map *map, int m)
{
    if (server->graph->active == 1) {
        print_player(server,
            server->entry
            [map->p_pos_team[m]]->player[map->p_pos[m]],
            server->entry
            [map->p_pos_team[m]]->player[map->p_pos[m]]->team,
            get_player_pos_by_fd(server,
                server->entry
                [map->p_pos_team[m]]->player[map->p_pos[m]]->fd,
                server->entry
                [map->p_pos_team[m]]->player[map->p_pos[m]]->team));

    }
}

void get_players_to_eject(s_serv *server, s_player *player, s_map *map)
{
    int max = map->mallocd * P_PER_MAP;
    for (int m = 0; m != max; m++) {
        if ((map->p_pos[m] != -1) &&
            server->entry[map->p_pos_team[m]]->
            player[map->p_pos[m]]->fd != player->fd) {
                no_more_than_2_embranchements(server, map, m);
                eject_player(server,
                server->entry[map->p_pos_team[m]]->player[map->p_pos[m]]);

        }
    }
}

void eject(s_serv *server, s_player *player)
{
    get_players_to_eject(server, player,
        server->map[player->y][player->x]);

    dprintf(player->fd, "ok\n");
    destroy_action(player->act);
}
