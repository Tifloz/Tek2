/*
** EPITECH PROJECT, 2019
** Gaëtan CHAUGNY
** File description:
** commands.h
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#include "args.h"
#include "server.h"

void id_command(s_client *c, s_args *a, int fd, const char *msg);

void map_command(s_client *c, s_args *a, int fd, const char *msg);

void ready_command(s_client *c, s_args *a, int fd, const char *msg);

void fire_command(s_client *c, s_args *a, int fd, char *msg);

typedef struct commands_s {
    void (*ptr)();
    char *name;
} commands_s;

static const commands_s dico[6] = {{&id_command, "ID"},
    {&map_command, "MAP"}, {&ready_command, "READY"},
    {&fire_command, "FIRE 0"}, {&fire_command, "FIRE 1"}, {NULL, NULL}};

void handle_command(char *command, s_client *c, s_args *a, int fd);

char **str_to_word_tab(char *str, char c);

char *get_next_line(int fd);

#endif