/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef NWP_MYFTP_2018_CMDS_H
#define NWP_MYFTP_2018_CMDS_H

#include "ftp.h"

cmd_t cmds[] = {{&cmd_user, "user"}, {&cmd_pass, "pass"}, {&cmd_quit, "quit"},
    {&cmd_pwd, "pwd"}, {&cmd_quit, "quit"}, {&cmd_help, "help"}, {NULL, "0"}};

#endif //NWP_MYFTP_2018_CMDS_H
