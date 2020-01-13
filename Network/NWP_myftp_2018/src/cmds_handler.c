/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include "ftp.h"
#include "cmds.h"

int cmds_handler(int sock, char *buff, client_t *client)
{
    int i = 0;
    short ret = 1;
    char *tmp = NULL;

    if (strlen(buff) == 1)
        return (1);
    strtok(buff, "\n");
    if (strchr(buff, 32)) {
        tmp = strndup(strchr(buff, 32) + 1, strlen(strchr(buff, 32) + 1));
        strtok(buff, " ");
    }
    to_lower_case(&buff);
    while (strcmp(buff, cmds[i].cmp) != 0 && strcmp(cmds[i].cmp, "0") != 0) {
        printf("%d\n", sock);
        i++;
    }
    if (strcmp(cmds[i].cmp, "0") != 0 && (!strcmp(buff, cmds[i].cmp)))
        cmds[i].ptr(sock, client, tmp);
    else
        write(sock, "500 Unknown command.\r\n", 22);
    free(tmp);
    return (ret);
};