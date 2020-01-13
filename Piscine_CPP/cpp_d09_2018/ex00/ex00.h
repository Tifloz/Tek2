/*
** EPITECH PROJECT, 2022
** cpp_d09_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D09_2018_EXO00_H
#define CPP_D09_2018_EXO00_H

typedef struct s_cthulhu {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct s_koala {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

cthulhu_t m_parent;

cthulhu_t *new_cthulhu();

void print_power(cthulhu_t *this);

void attack(cthulhu_t *this);

void sleeping(cthulhu_t *this);

koala_t *new_koala(char *name, char is_a_legend);

void eat(koala_t *this);

#endif //CPP_D09_2018_EXO00_H