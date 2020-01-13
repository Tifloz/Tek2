/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#ifndef CMD_FUNC_H
#define CMD_FUNC_H

#include "include.h"
#include "struct.h"

static void (*cmd_func[13])(s_serv *server, s_player *player) = {&forward,
&right, &left, &look, &inventory, &broadcast, &connect_nbr, &fork_p,
&eject, &take, &set, &incant, &error};

#endif //CMD_FUNC_H
