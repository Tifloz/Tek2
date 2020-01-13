/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

s_socket *init_socket(int port)
{
    s_socket *to_ret = malloc(sizeof(s_socket));
    uint16_t serverPort = port;

    to_ret->fd = socket(PF_INET, SOCK_STREAM, 0);
    to_ret->addr.sin_family = AF_INET;
    to_ret->addr.sin_port = htons(serverPort);
    to_ret->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(to_ret->fd, (struct sockaddr *)&to_ret->addr,
    sizeof(to_ret->addr));
    listen(to_ret->fd, 4096);
    return to_ret;
}
