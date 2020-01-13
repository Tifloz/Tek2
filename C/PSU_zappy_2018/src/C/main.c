/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void print_arg(void)
{
    printf("Usage :\n   ./zappy_server -p port -x width -y height -n name1 \
name2 ...  -c clientsNb -f freq\n\
Simple usage:\n\
valgrind ./zappy_server -p 8002 -x 5 -y 5 -n name1 name2 -c 5 -f 1\n");
}

s_waiting *first_waiter(void)
{
    s_waiting *to_ret = malloc(sizeof(s_waiting));

    to_ret->fd = -1;
    to_ret->team = -1;
    to_ret->prev = NULL;
    to_ret->next = NULL;
    return to_ret;
}

s_graph *init_graph(void)
{
    s_graph *to_ret = malloc(sizeof(s_graph));

    to_ret->fd = -1;
    to_ret->active = 0;
    return to_ret;
}

void init_serv(s_serv *server, s_parse parse)
{
    server->freq = parse.freq;
    server->max_per_team = parse.team_max;
    server->socket = init_socket(parse.port);
    server->team = init_teams(parse.teams,
        parse.team_max, parse.width, parse.height);
    get_map(parse.width, parse.height, server);
    server->wait = first_waiter();
    server->last = server->wait;
    server->graph = init_graph();
}

int main(int ac, char **av)
{
    s_parse parse;
    s_serv server;

    if (ac < 13) {
        print_arg();
        return 84;
    }
    signal(SIGPIPE, SIG_IGN);
    parse = parse_arg(ac, av);
    init_serv(&server, parse);
    get_entry_team(&server);
    serv_loop(server.socket, &server);
    free_server(&server);
    free_parse(&parse);
    return 0;
}
