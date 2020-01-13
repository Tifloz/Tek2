/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void check_input(s_serv *serv)
{
    char *buff = malloc(sizeof(char) * 42);
    size_t size = 42;

    getline(&buff, &size, stdin);
    if (strcmp(buff, "Quit\n") == 0) {
        if (serv->graph->active == 1) {
            dprintf(serv->graph->fd, "Quit\n");
            close(serv->graph->fd);
        }
        free_server(serv);
        free(buff);
        exit(0);
    }
    free(buff);
}

static int find_windob(char *str, int size)
{
    int i = 0;

    for (; i != size; i++) {
        if (str[i] == '\0')
            return i;
        if (str[i] == '\n' || str[i] == '\r')
            return i;
    }
    return size;
}

int read_from_client(int i, s_serv *server, struct timeval *select_clock)
{
    char buff[4096];
    int size;
    s_read tmp;

    size = recv(i, buff, 4096, 0);
    actualize_map(server, select_clock);
    if (size <= 0 || size > 4095)
        return 0;
    buff[find_windob(buff, size)] = '\0';
    if (identify_client(i, server, buff, &tmp) == 2)
        return 0;
    return 0;
}
