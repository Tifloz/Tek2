/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include "ftp.h"

void config_socket(struct sockaddr_in *sin, int port)
{
    sin->sin_family = AF_INET;
    sin->sin_port = htons(port);
    sin->sin_addr.s_addr = htonl(INADDR_ANY);
}

int open_socket(int sock, int port, char *path)
{
    struct sockaddr_in sin;

    config_socket(&sin, port);
    if ((bind(sock, (struct sockaddr *)&sin, sizeof(sin))) == -1) {
        close(sock);
        write(2, "Bind socket failed.\n", 20);
        exit(EXIT_FAILURE);
    }
    if ((listen(sock, 90000)) == -1) {
        close(sock);
        write(2, "Listen socket failed.\r\n", 23);
        exit(EXIT_FAILURE);
    }
    server_start(sock, path);
    return (0);
}

void reuse_socket(int sock)
{
    int boole = 1;

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &boole,
        sizeof(int)) < 0) {
        close(sock);
        printf("setsockopt failed\n");
        return;
    }
}

char *get_ip_server(int sock)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);

    if (getsockname(sock, (struct sockaddr *)&sin, &len) == -1) {
        close(sock);
        write(2, "getsockname failed.\n", 20);
        exit(EXIT_FAILURE);
    }
    return (strdup(inet_ntoa(sin.sin_addr)));
}