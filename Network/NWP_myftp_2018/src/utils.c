/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include "ftp.h"

char *get_ip(int sock)
{
    struct sockaddr_in sin;
    socklen_t len;

    len = sizeof(sin);
    if (getsockname(sock, (struct sockaddr *)&sin, &len) == -1) {
        close(sock);
        write(2, "getsockname failed.\n", 20);
        exit(EXIT_FAILURE);
    }
    return (strdup(inet_ntoa(sin.sin_addr)));
}

int is_logged(int sock, client_t *login)
{
    if (login->login != 84) {
        write(sock, "530 Please login with USER and PASS.\r\n", 38);
        return (0);
    }
    return (1);
}

void log_message(char *ip, char *msg)
{
    if (strlen(msg) <= 1)
        return;
    write(1, ip, strlen(ip));
    write(1, " ", 1);
    write(1, msg, strlen(msg));
}

char *getpwd(void)
{
    char *dir;

    if ((dir = malloc(sizeof(char) * 1024)) == NULL) {
        write(2, "Malloc failed.\n", 15);
        exit(EXIT_FAILURE);
    }
    getcwd(dir, 1024);
    dir[strlen(dir) + 1] = '\0';
    return (dir);
}

void to_lower_case(char **str)
{
    int i = -1;

    while ((*str)[++i])
        (*str)[i] = tolower((*str)[i]);
}