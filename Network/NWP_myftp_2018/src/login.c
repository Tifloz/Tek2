/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include <ftp.h>

void init_client(int sock, client_t *login, struct sockaddr_in *a_sin)
{
    login->user = NULL;
    login->pass = NULL;
    login->state = 0;
    login->ip_serv = get_ip(sock);
    login->addr = inet_ntoa(a_sin->sin_addr);
    login->port = ntohs(a_sin->sin_port);
    login->login = 1;
    login->socket_nb = sock;
}

void login(int sock, network_t *sockets_utils, char *path, client_t *client)
{
    init_client(sock, client, &sockets_utils->a_sin);
    if (!access(path, F_OK)) {
        chdir(path);
        client->p_dir = getpwd();
    }
    write(sock, "220 Service ready for new user.\r\n", 32);
    log_message(client->addr, " is connected to the server.\n");
}