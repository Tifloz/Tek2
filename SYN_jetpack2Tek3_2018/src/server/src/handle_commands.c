/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** client.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "commands.h"
#include "server.h"

#define SIZE 1024

void handle_command(char *command, s_client *c, s_args *a, int fd)
{
    for (int i = 0; dico[i].name; i++) {
        if (strcmp(command, dico[i].name) == 0) {
            dico[i].ptr(c, a, fd, command);
            return;
        }
    }
    printf("Unknown command: %s\n", command);
}

void get_message(int client_fd, s_client *c, s_args *a)
{
    char *buffer = malloc(sizeof(char) * SIZE);

    if (buffer == NULL)
        exit(84);
    buffer = get_next_line(client_fd);
    if (!buffer) {
        printf("Bad command\n");
        exit(84);
    }
    if (strlen(buffer) <= 0) {
        printf("Error in message\n");
        close(client_fd);
        return;
    }
    printf("RECEIVED ~> %s\n", buffer);
    handle_command(buffer, c, a, client_fd);
}

void send_message(int fd, char *message, ...)
{
    va_list args;
    int len;
    char *buffer = malloc(sizeof(char) * SIZE);

    va_start(args, message);
    len = vsprintf(buffer, strdup(message), args);
    printf("SEND ~> %s\n", buffer);
    write(fd, buffer, len);
    va_end(args);
}