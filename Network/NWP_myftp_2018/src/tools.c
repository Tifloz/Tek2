/*
** EPITECH PROJECT, 2022
** NWP_myftp_2018
** File description:
** Created by Florian Louvet,
*/
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <linux/limits.h>
#include <ftp.h>

int ftp_init(network_t **raw, int argc, char **argv)
{
    network_t *x;

    if ((x = malloc(sizeof(network_t))) == NULL)
        return (-1);
    x->port = parsing_option(argc, argv, 'p');
    x->protocole = getprotobyname("TCP");
    x->quiet = parsing_option_exist(argc, argv, 'q');
    x->magicNumber = parsing_option(argc, argv, 'x');
    x->queue = parsing_option(argc, argv, 'w');
    x->bin_path = malloc(PATH_MAX);
    x->bin_path = getcwd(x->bin_path, PATH_MAX);
    if (x->quiet == -1)
    {
        print_carac("port         ", x->port, DEFAULT_PORT);
        print_carac_db(parsing_option_db(argc, argv, x->db_name, &x->db));
        printf("~ prot         : %sTCP%s\n\n", "\033[0;33m", "\033[0;0m");
    }
    db_init(x);
    *raw = x;
    return (1);
}
