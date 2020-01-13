/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <fcntl.h>
#include "struct.h"
#include <signal.h>

/*  INIT    */
s_socket *init_socket(int port);
//s_player **malloc_player(int max);
s_team *init_teams(char **teams, int max_player, int maxy, int maxx);
void get_entry_team(s_serv *serv);
void get_map(int x, int y, s_serv *server);
// INIT

/*  TOOLS */
char *my_strcat(char *str1, const char *str2, int n);
//TOOLS

/*  PARSE */
char **get_team_names(char **tab);
s_parse parse_arg(int ac, char **av);
void get_port(char *str, s_parse *parse);
void get_width(char *str, s_parse *parse);
void get_height(char *str, s_parse *parse);
void get_teammax(char *str, s_parse *parse);
void get_freq(char *str, s_parse *parse);
//PARSE

/*  Server  */
void serv_loop(s_socket *socket, s_serv *server);
void accept_new_connection(struct sockaddr_in clientname,
int *new, s_serv *serv, fd_set *active_fd_set);
void new_player(s_serv *server, int fd, char *buff);
void delete_waiting(s_waiting *actual, s_serv *server);
int identify_client(int i, s_serv *server, char *buff, s_read *to_ret);
void actualize_map(s_serv *server, struct timeval *select_clock);
int read_from_client(int i, s_serv *server, struct timeval *select_clock);
void check_input(s_serv *serv);

int get_player_pos_by_fd(s_serv *serv, int fd, int team);
void player_move_on_map(s_serv *server, s_player *player, int dir);

void player_action(s_serv *serv, s_player *player);
s_player *get_player(int maxy, int maxx);
void get_players_to_eject(s_serv *server, s_player *player, s_map *map);
void actualise_free_pos(s_map *map);
void player_move_to(s_serv *server, s_player *player, int y, int x);
void add_player_to(s_serv *server, s_map *map, s_player *player,
    __attribute__((unused))int p_pos);
void get_bigger_map(s_map *to_bigger);

int match_new(char *buff, char **teams);
int find_active(s_serv *serv, s_team *team, int p_pt);
void new_player_random_pos(s_serv *server, s_player *player);
void remove_player_from(s_map *map, s_player *player, int p_pos);
void destroy_action(s_action *act);
// SERVER

/*  HANDLE PLAYERS */
void set_action(s_serv *serv, s_player *player, int command, char *buff);
int is_command(char *str);
void check_players(s_serv *serv, struct timeval *select_clock);
void destroy_action(s_action *act);
int find_object(char *str);
void first_tile(s_serv *serv, s_map ***map, s_player *player);
// HANDLE PLAYERS

/*  GRAPH   */
void print_tile(s_serv *server, s_map *map, int x, int y);
void print_players(s_serv *server);
void print_player(s_serv *server, s_player *player, int i, int j);
void send_data_to_graph(s_serv *server, int fd);
char *get_team_names_graph(char **str, int nb);
/*  COMMANDs    */
void player_die(s_serv *serv, s_player *player);
void broadcast(s_serv *server, s_player *player);
void connect_nbr(s_serv *server, s_player *player);
void eject(s_serv *server, s_player *player);
void fork_p(s_serv *server, s_player *player);
void forward(s_serv *server, s_player *player);
void incant(s_serv *server, s_player *player);
int check_tile(s_map *map, int *stock);
void get_incant(s_incant *incant, s_serv *server, s_player *player);
void norm_norm_norm(s_player *player, s_incant *incant);
void free_incant(s_incant *incant);


void inventory(s_serv *server, s_player *player);
void left(s_serv *server, s_player *player);
void look(s_serv *server, s_player *player);
void get_tile_look(s_serv *server, char *tmp, int x, int y);
void look_up(s_serv *server, s_player *player, int lvl, char *to_send);
void look_down(s_serv *server, s_player *player, int lvl, char *to_send);
void look_right(s_serv *server, s_player *player, int lvl, char *to_send);
void look_left(s_serv *server, s_player *player, int lvl, char *to_send);


void right(s_serv *server, s_player *player);
void set(s_serv *server, s_player *player);
void take(s_serv *server, s_player *player);
void error(s_serv *server, s_player *player);
//  COMMANDS

/*  FREE    */
void free_server(s_serv *serv);
void free_parse(s_parse *parse);
//  FREE
#endif // INCLUDE_H_
