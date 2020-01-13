/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef NWP_MYFTP_2018_FTP_H
#define NWP_MYFTP_2018_FTP_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <zconf.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <ctype.h>

#define DEFAULT_PORT 5050

typedef struct client_s {
    short state;
    char *ip_serv;
    char *addr;
    uint16_t port;
    char *user;
    char *pass;
    short login;
    char *p_dir;
    int sdata;
    int socket_nb;
} client_t;

typedef struct network_s {
    struct sockaddr_in a_sin;
    socklen_t len;
    int socket;
    int new_socket;
    client_t clients[30];
    int activity;
    int max_sd;
    fd_set readfds;
} network_t;

typedef struct cmd_s {
    int (*ptr)(int sock, client_t *client, char *buff);

    char *cmp;
} cmd_t;

void login(int sock, network_t *sockets_utils, char *path, client_t *client);

void init_client(int sock, client_t *login, struct sockaddr_in *a_sin);

int is_logged(int sock, client_t *login);

char *get_ip(int sock);

void to_lower_case(char **str);

char *getpwd(void);

int cmd_help(int sock, client_t *client, char *buff);

int cmd_user(int sock, client_t *client, char *buff);

int cmd_pass(int sock, client_t *client, char *buff);

int cmd_pwd(int sock, client_t *client, char *buff);

int cmd_quit(int sock, client_t *login, char *buff);

void server_start(int sock, char *path);

int cmds_handler(int sock, char *buff, client_t *client);

void log_message(char *ip, char *msg);

#endif //NWP_MYFTP_2018_FTP_H
