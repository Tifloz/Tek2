/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** socket hpp
*/

#ifndef HPP_SERVER_SOCKET_H
#define HPP_SERVER_SOCKET_H

#ifdef WIN32

#include <winsock2.h>

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

#endif

#endif
