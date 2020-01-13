/*
** EPITECH PROJECT, 2022
** NWP_mychap_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include "parser.h"
#include "my_chap.h"

void resolver(parser_t *args)
{
    struct hostent *host;

    if ((host = gethostbyname(optarg)) == NULL) {
        fprintf(stderr, "No such hostname: %s\n", optarg);
        exit(84);
    }
    args->target = strdup(
        inet_ntoa(*((struct in_addr **)host->h_addr_list)[0]));
}

void parser(int option, parser_t *args)
{
    switch (option) {
    case 't':
        resolver(args);
        break;
    case 'p':
        args->port = atoi(optarg);
        break;
    case 'P':
        args->password = optarg;
        break;
    case '?':
        break;
    default:
        abort();
    }
}

int main(int argc, char **argv)
{
    int option;
    int index;
    parser_t args = {NULL, 0, NULL, 0};

    srand(time(NULL));
    args.source_port = (rand() + 1024) % 5000;
    while (42) {
        index = 0;
        option = getopt_long(argc, argv, "t:p:P:", long_options, &index);
        if (option == -1)
            break;
        parser(option, &args);
    }
    create_socket(&args);
    if (args.target == NULL || args.password == NULL || args.port == 0)
        return (84);
    return (0);
}
