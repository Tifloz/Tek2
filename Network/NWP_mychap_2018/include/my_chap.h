/*
** EPITECH PROJECT, 2022
** NWP_mychap_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef NWP_MYCHAP_2018_MY_CHAP_H
#define NWP_MYCHAP_2018_MY_CHAP_H

#include <netinet/in.h>

typedef struct parser_s {
    char *target;
    int port;
    char *password;
    int source_port;
} parser_t;

typedef struct socket_utils_s {
    unsigned char datagram[4096];
    char source_ip[32];
    char *data;
    char *pseudogram;
    struct iphdr *iph;
    struct udphdr *udph;
    struct sockaddr_in sin;
} socket_utils_t;

void create_socket(parser_t *args);

#endif //NWP_MYCHAP_2018_MY_CHAP_H
