/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void new_player_next(s_serv *server, int fd, int tmp)
{
    server->all++;
    server->entry[tmp]->player[server->last_player[tmp]]->fd = fd;
    server->entry[tmp]->player[server->last_player[tmp]]->team = tmp;
    if (server->entry[tmp]->player[server->last_player[tmp]]->is_egg == 0) {
        new_player_random_pos(server,
            server->entry[tmp]->player[server->last_player[tmp]]);
        server->map[server->entry[tmp]->player[server->last_player[tmp]]->y][
    server->entry[tmp]->player[server->last_player[tmp]]->x]->stock[0] += 20;
        }
    server->entry[tmp]->player[server->last_player[tmp]]->active = 1;
    server->entry[tmp]->player[server->last_player[tmp]]->inv->last_food
    = time(NULL);
    server->entry[tmp]->player[server->last_player[tmp]]->is_egg = 0;
    first_tile(server,
        server->map, server->entry[tmp]->player[server->last_player[tmp]]);
    dprintf(server->entry[tmp]->player[server->last_player[tmp]]->fd,
    "%d\n", (server->max_per_team - (server->last_player[tmp] + 1)
    + server->more_player[tmp]));
    dprintf(server->entry[tmp]->player[server->last_player[tmp]]->fd
    , "%d %d\n", server->x, server->y);
    server->last_player[tmp] = find_active(server, server->entry[tmp], tmp);
}

void get_graph(s_serv *server, int fd)
{
    if (server->graph->active == 0) {
        server->graph->fd = fd;
        server->graph->active = 1;
        send_data_to_graph(server, fd);
    } else {
        dprintf(fd, "Graphic already connected\n");
        close(fd);
        FD_CLR(fd, &server->active_fd_set);
    }
}

void new_player(s_serv *server, int fd, char *buff)
{
    int tmp = 0;

    if (strcasecmp(buff, "graphic") == 0) {
        get_graph(server, fd);
        dprintf(fd, "YOU ARE GRAPHIC\n");
        return;
    }
    tmp = match_new(buff, server->names);
    if (server->last_player[tmp] >=
        (server->max_per_team + server->more_player[tmp])) {
        dprintf(fd, "already full team\n");
        close(fd);
        FD_CLR(fd, &server->active_fd_set);
        return;
    }
    if (tmp != -1) {
        new_player_next(server, fd, tmp);
    } else {
        dprintf(fd, "wrong team name\n");
        close(fd);
        FD_CLR(fd, &server->active_fd_set);
    }
}

void delete_waiting(s_waiting *actual, s_serv *server)
{
    if (actual->next == NULL) {
        actual->prev->next = NULL;
        server->last = actual->prev;
        free(actual);
        return;
    }
    else if (actual->prev == NULL) {
        actual->next->prev = NULL;
        free(actual);
        return;
    }
    actual->next->prev = actual->prev;
    actual->prev->next = actual->next;
    free(actual);
    return;
}

int identify_client(int i, s_serv *server, char *buff,
    __attribute__((unused))s_read *to_ret)
{
    int tmp_cmd;

    for (s_waiting *tmp = server->wait; tmp != NULL; tmp = tmp->next)
        if (tmp->fd == i) {
            new_player(server, tmp->fd, buff);
            delete_waiting(tmp, server);
            return 2;
        }
    for (int j = 0; server->entry[j] != NULL; j++)
        for (int k = 0; server->entry[j]->player[k] != NULL; k++)
            if (server->entry[j]->player[k]->active == 1 &&
                server->entry[j]->player[k]->fd == i) {
                if (server->entry[j]->player[k]->act->many < 9) {
                    tmp_cmd = is_command(buff);
                set_action(server, server->entry[j]->player[k], tmp_cmd, buff);
                }
                return 1;
            }
    return 2;
}
