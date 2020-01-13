/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

static fd_set handle_active_set(fd_set active)
{
    return active;
}

void start_loop(s_serv *server, s_socket *socket)
{
    server->last_tick = time(NULL);
    FD_ZERO(&server->active_fd_set);
    FD_SET(0, &server->active_fd_set);
    FD_SET(socket->fd, &server->active_fd_set);
}

void read_loop(s_serv *server, struct timeval *select_clock,
    fd_set *read_fd_set)
{
    struct sockaddr_in clientname;
    int new;

    for (int i = 0; i != FD_SETSIZE; i++)
        if (FD_ISSET(i, read_fd_set)) {
            if (i == 0)
                check_input(server);
            else if (i == server->socket->fd && server->all < 1019)
                accept_new_connection(clientname,
                &new, server, &server->active_fd_set);
            else if (read_from_client(i, server, select_clock) < 0) {
                close(i);
                FD_CLR(i, &server->active_fd_set);
                break;
            }
        }
}

void serv_loop(s_socket *socket, s_serv *server)
{
    fd_set read_fd_set;
    struct timeval select_clock = {0, 0};

    start_loop(server, socket);
    while (1) {
        read_fd_set = handle_active_set(server->active_fd_set);
        select(FD_SETSIZE, &read_fd_set, NULL, NULL, &select_clock) == 0 ?
        (actualize_map(server, &select_clock)) : 1;
        read_loop(server, &select_clock, &read_fd_set);
    }
}
