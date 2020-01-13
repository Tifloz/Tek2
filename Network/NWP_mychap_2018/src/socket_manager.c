/*
** EPITECH PROJECT, 2022
** NWP_mychap_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "my_chap.h"

uint16_t checksum(uint8_t *data, unsigned int size)
{
    int i;
    int sum = 0;
    uint16_t *p = (uint16_t *)data;

    for (i = 0; i < size; i += 2) {
        sum += *(p++);
    }
    uint16_t carry = sum >> 16;
    uint16_t tmp = 0x0000ffff & sum;
    uint16_t res = ~(tmp + carry);

    return res;
}

void ip_filler(socket_utils_t *utils, parser_t *args)
{
    utils->sin.sin_family = AF_INET;
    utils->sin.sin_port = htons(args->source_port);
    utils->sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    utils->iph->ihl = 5;
    utils->iph->version = 4;
    utils->iph->tos = 16;
    utils->iph->tot_len = sizeof(struct iphdr) + sizeof(struct udphdr) + 64;
    utils->iph->id = 0;
    utils->iph->frag_off = 0;
    utils->iph->ttl = 255;
    utils->iph->protocol = IPPROTO_UDP;
    utils->iph->check = 0;
    utils->iph->saddr = 0;
    utils->iph->daddr = inet_addr(args->target);
    utils->udph->len = htons(sizeof(*utils->udph) + strlen(utils->data));
    utils->udph->check = checksum(utils->datagram, utils->iph->tot_len);
    utils->udph->dest = htons(args->port);
}

void create_socket(parser_t *args)
{
    socket_utils_t utils;
    int optval = 1;
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

    if (sock == -1) {
        perror("Failed to create raw socket");
        exit(84);
    }
    memset(utils.datagram, 0, 4096);
    utils.iph = (struct iphdr *)utils.datagram;
    utils.udph = (struct udphdr *)(utils.datagram + sizeof(struct ip));
    utils.data = utils.datagram + sizeof(struct iphdr) + sizeof(struct udphdr);
    strcpy(utils.data, "client hello");
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (void *)&optval,
        sizeof optval) < 0)
        perror("setsockopt broadcast");
    ip_filler(&utils, args);
    if (sendto(sock, utils.datagram, utils.iph->tot_len, 0,
        (struct sockaddr *)&utils.sin, sizeof(utils.sin)), 0) {
        perror("endto failed");
    }
}