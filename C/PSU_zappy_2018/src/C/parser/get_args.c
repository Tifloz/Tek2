/*
** EPITECH PROJECT, 2018
** NAME_OF_THE_PROJECT
** File description:
** Un truc
*/

#include "include.h"
#include "struct.h"

char **get_team_names(char **tab)
{
    int to_malloc = 0;
    char **to_ret;

    for (int i = 0; tab[i] != NULL && tab[i][0] != '-'; i++, to_malloc++);
    to_ret = malloc(sizeof(char *) * (to_malloc +1));
    for (int i = 0; i != to_malloc; i++) {
        to_ret[i] = strdup(tab[i]);
        to_ret[i + 1] = NULL;
    }
    return to_ret;
}

s_parse parse_arg(int ac, char **av)
{
    s_parse to_ret;
    char *dico[7] = {"-p", "-x", "-y", "-c", "-f", NULL};
    void (*func[5])(char *str, s_parse *parse) = { &get_port,
        &get_width, &get_height, &get_teammax, &get_freq};

    for (int i = 0; i != ac; i++)
        for (int j = 0; dico[j] != NULL; j++) {
            if (strcmp(dico[j], av[i]) == 0) {
                (func[j])(av[i + 1], &to_ret);
                break;
            }
            else if (strcmp("-n", av[i]) == 0) {
                to_ret.teams = get_team_names(&av[i + 1]);
                break;
            }
        }
    return to_ret;
}
