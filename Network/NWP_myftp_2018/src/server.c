/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include "ftp.h"
#include "socket_utils.h"

void main_loop(int sock, network_t *socket_utils)
{
    FD_ZERO(&socket_utils->readfds);
    FD_SET(sock, &socket_utils->readfds);
    socket_utils->max_sd = sock;
    for (int i = 0; i < 30; i++) {
        if (socket_utils->clients[i].socket_nb > 0)
            FD_SET(socket_utils->clients[i].socket_nb, &socket_utils->readfds);
        if (socket_utils->clients[i].socket_nb > socket_utils->max_sd)
            socket_utils->max_sd = socket_utils->clients[i].socket_nb;
    }
    socket_utils->activity = select(socket_utils->max_sd + 1,
        &socket_utils->readfds, NULL, NULL, NULL);
    if ((socket_utils->activity < 0) && (errno != EINTR)) {
        printf("select error");
    }
}

void handle_serv(client_t client)
{
    char buff[4096];
    bzero(buff, 4096);
    if (read(client.socket_nb, buff, 4096) == 0) {
        cmd_quit(client.socket_nb, &client, buff);
    }
    log_message(client.addr, buff);
    strtok(buff, "\r");
    cmds_handler(client.socket_nb, buff, &client);
}

void server_start(int sock, char *path)
{
    network_t socket_utils;
    socklen_t len = sizeof(socket_utils.a_sin);
    int nb_client = 0;

    for (int i = 0; i < 30; i++)
        socket_utils.clients[i].socket_nb = 0;
    while (1) {
        main_loop(sock, &socket_utils);
        if (FD_ISSET(sock, &socket_utils.readfds)) {
            if ((socket_utils.new_socket = accept(sock,
                (struct sockaddr *)&socket_utils.a_sin, &len)) == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            login(socket_utils.new_socket, &socket_utils, path,
                &socket_utils.clients[nb_client]);
        }
        for (int i = 0; i < 30; i++) {
            if (FD_ISSET(socket_utils.clients[i].socket_nb,
                &socket_utils.readfds))
                handle_serv(socket_utils.clients[i]);
        }
        nb_client++;
    }
}

int main(int ac, char **av)
{
    int sock;

    if (ac != 3) {
        printf("USAGE: ./myftp [port] [path].\n");
        return (0);
    }
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        close(sock);
        perror("Create socket_utils.socket failed.\n");
        return (-84);
    }
    reuse_socket(sock);
    open_socket(sock, atoi(av[1]), av[2]);
    return (0);
}