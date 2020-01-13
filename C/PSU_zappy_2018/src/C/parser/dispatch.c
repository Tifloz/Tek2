/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

void get_port(char *str, s_parse *parse)
{
    if (atoi(str) < 8000) {
        fprintf(stderr, "Error with the port");
        exit(84);
    }
    parse->port = atoi(str);
}

void get_width(char *str, s_parse *parse)
{
    if (atoi(str) < 10 || atoi(str) > 30) {
        fprintf(stderr, "Error with the width");
        exit(84);
    }
    parse->width = atoi(str);
}

void get_height(char *str, s_parse *parse)
{
    if (atoi(str) < 10 || atoi(str) > 30) {
        fprintf(stderr, "Error with the height");
        exit(84);
    }
    parse->height = atoi(str);
}

void get_teammax(char *str, s_parse *parse)
{
    if (atoi(str) <= 0) {
        fprintf(stderr, "Error with the number of members of each team");
        exit(84);
    }
    parse->team_max = atoi(str);
}

void get_freq(char *str, s_parse *parse)
{
    if (atof(str) <= 0) {
        fprintf(stderr, "Error with the frequency");
        exit(84);
    }
    parse->freq = atof(str);
}
