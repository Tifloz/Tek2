/*
** EPITECH PROJECT, 2022
** cpp_d03_2018
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include <string.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this)
        return (NULL);
    return (this->str);
}

int empty(const string_t *this)
{
    if (!this || !this->str)
        return (1);
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}

void string_init_functions(string_t *this)
{
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->split_c = &split_c;
    this->split_s = &split_s;
}

void string_init(string_t *this, char const *s)
{
    if (!this)
        return;
    this->str = NULL;
    if (s)
        this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    string_init_functions(this);
}

void string_destroy(string_t *this)
{
    if (this && this->str) {
        free(this->str);
        this->str = NULL;
    }
}