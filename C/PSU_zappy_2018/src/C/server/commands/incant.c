/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"
#include "incant.h"

void norm_again_and_again(s_serv *server, s_player *player,
    s_incant *incant, int i)
{
    if (server->map[player->y][player->x]->p_pos[i] != -1) {
        if (server->entry[server->map[player->y][player->x]->p_pos_team[i]]
            ->player[server->map [player->y][player->x]->p_pos[i]]->active
            == 1 && server->entry[server->map[player->y][player->x]
            ->p_pos_team[i]]->player[server->map[player->y]
            [player->x]->p_pos[i]]->lvl->lvl == player->lvl->lvl) {
            incant->to_send[incant->tmp_nb_player] =
            server->entry[server->map[player->y][player->x]
            ->p_pos_team[i]]->player
            [server->map[player->y][player->x]->p_pos[i]]->fd;
            incant->tmp_pt[incant->tmp_nb_player] =
            server->map[player->y][player->x]->p_pos_team[i];
            incant->tmp_p[incant->tmp_nb_player] =
            server->map[player->y][player->x]->p_pos[i];
            incant->tmp_nb_player++;
        } else {
            incant->tmp_pt[incant->tmp_nb_player] = -1;
            incant->tmp_p[incant->tmp_nb_player] = -1;
            incant->tmp_nb_player++;
        }
    }
}

void print_with_norm(s_serv *server, s_player *player, s_incant *incant, int i)
{
    if (incant->tmp_pt[i] != -1 && incant->tmp_p[i] != -1) {
    server->entry[incant->tmp_pt[i]]->player[incant->tmp_p[i]]->lvl->lvl++;
    dprintf(incant->to_send[i],
        "Elevation underway Current level: %d\n", player->lvl->lvl);
        if (server->graph->active == 1) {
                print_player(server, player, player->team,
                get_player_pos_by_fd(server, player->fd, player->team));
            }
        }
}

void incant(s_serv *server, s_player *player)
{
    s_incant incant;

    get_incant(&incant, server, player);
    if (check_tile(server->map[player->y][player->x],
        to_stock[player->lvl->lvl - 1]) == 0) {
        norm_norm_norm(player, &incant);
        return;
    }
    if (player->lvl->lvl == 8)
        dprintf(player->fd, "ko\n");
    for (int i = 0; i != incant.max; i++)
        norm_again_and_again(server, player, &incant, i);
    if (incant.tmp_nb_player >= players[player->lvl->lvl])
        for (int i = 0; i != (server->map[player->y][player->x]->players); i++)
            print_with_norm(server, player, &incant, i);
    destroy_action(player->act);
    free_incant(&incant);
}
