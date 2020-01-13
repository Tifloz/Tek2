/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct t_parse s_parse;
typedef struct t_serv s_serv;
typedef struct t_socket s_socket;
typedef struct t_player s_player;
typedef struct t_team s_team;
typedef struct t_entry s_entry;
typedef struct t_map s_map;
typedef struct t_waiting s_waiting;
typedef struct t_read s_read;
typedef struct t_action s_action;
typedef struct t_inv s_inv;
typedef struct t_lvl s_lvl;
typedef struct t_graph s_graph;
typedef struct t_incant s_incant;
#define REFRESH_CALC(time, freq) ({(time / freq);})

#define P_PER_MAP (11)

enum player_act
{
    FORWARD,
    RIGHT,
    LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT,
    FORK,
    EJECT,
    TAKE,
    SET,
    INCANT,
};

struct t_incant
{
    int *to_send;
    int *tmp_pt;
    int *tmp_p;
    int max;
    int tmp_nb_player;
};

struct t_read
{
    int team;
    int player;
    int cmd;
};

struct t_parse
{
    int port;
    int width;
    int height;
    char **teams;
    int team_max;
    float freq;
};

struct t_entry
{
    s_team *point;
};

struct t_waiting
{
    int fd;
    int team;
    s_waiting *next;
    s_waiting *prev;
};

struct t_serv
{
    int all;
    int nb_team;
    int max_per_team;
    int *more_player;
    int *last_player;
    int *last_id_team;
    fd_set active_fd_set;
    time_t last_tick;
    float freq;
    int y;
    int x;
    s_graph *graph;
    s_socket *socket;
    s_team *team;
    s_team **entry;
    char **names;
    s_map ***map;
    s_waiting *wait;
    s_waiting *last;
};

struct t_graph
{
    int fd;
    int active;
};

struct t_map
{
    int stock[7];
    int *p_pos_team;
    int *p_pos;
    int players;
    int mallocd;
    int next_free_pos;
};

struct t_player
{
    int id;
    int x;
    int y;
    int team;
    int active;
    int fd;
    int is_egg;
    int egg_time;
    s_lvl *lvl;
    s_action *act;
    s_socket *sock;
    s_inv *inv;
};

struct t_lvl
{
    int lvl;
    int dir;
};

struct t_inv
{
    int stock[7];
    int food;
    int last_food;
    int linemate;
    int deuramere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

struct t_action
{
    int many;
    int acts[11];
    char *act_str[11];
    int time[11];
    int start[11];
};

struct t_team
{
    char *name;
    s_team *next;
    s_team *prev;
    s_player **player;
};

struct t_socket
{
    int fd;
    struct sockaddr_in addr;
};

#endif // STRUCT_H_
