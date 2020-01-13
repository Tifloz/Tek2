/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D03_2018_STRING_H
#define CPP_D03_2018_STRING_H

#include <stdlib.h>

typedef struct s_string string_t;

struct s_string {
    char *str;

    void (*assign_s)(string_t *this, const string_t *str);

    void (*assign_c)(string_t *this, const char *s);

    void (*append_s)(string_t *this, const string_t *ap);

    void (*append_c)(string_t *this, const char *ap);

    char (*at)(const string_t *this, size_t pos);

    void (*clear)(string_t *this);

    int (*size)(const string_t *this);

    int (*compare_s)(const string_t *this, const string_t *str);

    int (*compare_c)(const string_t *this, const char *str);

    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);

    const char *(*c_str)(const string_t *this);

    int (*empty)(const string_t *this);

    int (*find_s)(const string_t *this, const string_t *str, size_t pos);

    int (*find_c)(const string_t *this, const char *str, size_t pos);

    void (*insert_c)(string_t *this, size_t pos, const char *str);

    void (*insert_s)(string_t *this, size_t pos, const string_t *str);

    int (*to_int)(const string_t *this);

    string_t **(*split_s)(const string_t *this, char separator);

    char **(*split_c)(const string_t *this, char separator);
};

void string_init(string_t *this, char const *s);

void string_destroy(string_t *this);

void assign_s(string_t *this, const string_t *str);

void assign_c(string_t *this, const char *s);

void append_s(string_t *this, const string_t *ap);

void append_c(string_t *this, const char *ap);

char at(const string_t *this, size_t pos);

void clear(string_t *this);

int size(const string_t *this);

int compare_s(const string_t *this, const string_t *str);

int compare_c(const string_t *this, const char *str);

size_t copy(const string_t *this, char *s, size_t n, size_t pos);

const char *c_str(const string_t *this);

int empty(const string_t *this);

int find_s(const string_t *this, const string_t *str, size_t pos);

int find_c(const string_t *this, const char *str, size_t pos);

void insert_c(string_t *this, size_t pos, const char *str);

void insert_s(string_t *this, size_t pos, const string_t *str);

int to_int(const string_t *this);

string_t **split_s(const string_t *this, char separator);

char *my_clean_str(char *str);

char *my_strcat(char *dest, char const *src);

char **my_str_to_wordarray(char *str, char c);

char **split_c(const string_t *this, char separator);

#endif //CPP_D03_2018_STRING_H
