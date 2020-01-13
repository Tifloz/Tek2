/*
** EPITECH PROJECT, 2022
** NWP_mychap_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef NWP_MYCHAP_2018_PARSER_H
#define NWP_MYCHAP_2018_PARSER_H

#include <getopt.h>

struct option long_options[] = {{"target", required_argument, 0, 't'},
    {"port", required_argument, 0, 'p'},
    {"password", required_argument, 0, 'P'}, {0, 0, 0, 0}};

#endif //NWP_MYCHAP_2018_PARSER_H
