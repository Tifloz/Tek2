/*
** EPITECH PROJECT, 2022
** SYN_jetpack2Tek3_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>
#include <getopt.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <client.h>
#include <pthread.h>
#include "parser.h"
#include "network.h"

void resolver(network_t *args)
{
    struct hostent *host;

    if ((host = gethostbyname(optarg)) == NULL) {
        fprintf(stderr, "No such hostname: %s\n", optarg);
        exit(84);
    }
    args->ip = strdup(inet_ntoa(*((struct in_addr **)host->h_addr_list)[0]));
}

void help(int code)
{
    fprintf(stderr, "USAGE : ./clientJ2T3 -h <ip> -p <port>\n");
    exit(code);
}

void parser(int option, network_t *args)
{
    switch (option) {
    case 'h':
        resolver(args);
        break;
    case 'p':
        args->port = atoi(optarg);
        if (args->port <= 0)
            help(84);
        break;
    default:
        help(84);
    }
}

void init_network_struct(network_t *network_info)
{
    network_info->ip = NULL;
    network_info->map = NULL;
    network_info->port = 0;
    network_info->sock_fd = -1;
    network_info->id = 0;
    network_info->b_id = no_argument;
    network_info->b_map = no_argument;
    network_info->start = 0;
    network_info->endgame = false;
    network_info->connected = false;
    network_info->game.players[0].id = 0;
    network_info->game.players[1].id = 0;
    network_info->game.players[0].coin = 0;
    network_info->game.players[1].coin = 0;
    network_info->error = false;
}

int main(int argc, char **argv)
{
    int option;
    network_t network_info;
    int ret;

    init_network_struct(&network_info);
    while (42) {
        option = getopt(argc, argv, "h:p:");
        if (option == -1)
            break;
        parser(option, &network_info);
    }
    if (network_info.ip == NULL || network_info.port == 0)
        help(84);
    pthread_create(&network_info.net_thread, NULL, launch_network,
        &network_info);
    (run(&network_info) == 1) ? (ret = 84) : (ret = 0);
    free(network_info.ip);
    return (ret);
}