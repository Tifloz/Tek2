/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef NWP_MYFTP_2018_SOCKET_UTILS_H
#define NWP_MYFTP_2018_SOCKET_UTILS_H

void config_socket(struct sockaddr_in *sin, int port);
int open_socket(int sock, int port, char *path);
void reuse_socket(int sock);


#endif //NWP_MYFTP_2018_SOCKET_UTILS_H
