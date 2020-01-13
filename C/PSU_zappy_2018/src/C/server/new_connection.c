/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

s_waiting *new_waiter(s_waiting *last)
{
    s_waiting *to_ret = malloc(sizeof(s_waiting));

    if (last->next != NULL)
        while (last->next != NULL)
            last = last->next;
    to_ret->team = -1;
    to_ret->next = malloc(sizeof(s_waiting));
    to_ret->next = NULL;
    to_ret->prev = last;
    last->next = to_ret;
    last = to_ret;
    return to_ret;
}


void accept_new_connection(struct sockaddr_in clientname,
    int *new, s_serv *serv, fd_set *active_fd_set)
{
    size_t size;

    s_waiting *actual = new_waiter(serv->last);
    size = sizeof(clientname);
    actual->fd = accept(serv->socket->fd, (struct sockaddr *)&clientname,
    (socklen_t *)&size);
    if (actual->fd < 0)
        exit(0);
    FD_SET(actual->fd, active_fd_set);
    (*new) = actual->fd;
}
