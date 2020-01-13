/*
** EPITECH PROJECT, 2022
** cppd012018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "char.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this)
        this->x = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static const char *string(CharClass *this)
{
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Char (%c)>", this->x);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Char (%c)>", this->x);
    return (str);
}

static const Object *sub(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return new(Char, a->x - b->x);
    return NULL;
}

static const Object *add(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return new(Char, a->x + b->x);
    return NULL;
}

static const Object *exec_mul(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return new(Char, a->x * b->x);
    return NULL;
}

static const Object *exec_div(const CharClass *a, const CharClass *b)
{
    char value = '\0';

    if (a && b) {
        value = (char)(b->x == 0 ? 0 : a->x / b->x);
        return new(Char, value);
    }
    return NULL;
}

static bool equal(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return a->x == b->x ? true : false;
    return false;
}

static bool great_than(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return a->x > b->x ? true : false;
    return false;
}

static bool lower_than(const CharClass *a, const CharClass *b)
{
    if (a && b)
        return a->x < b->x ? true : false;
    return false;
}

static CharClass _description = {
    {.__size__ = sizeof(CharClass), .__name__ = "Char", .__ctor__ = (ctor_t)&Char_ctor, .__dtor__ = (dtor_t)&Char_dtor, .__str__ = (to_string_t)&string, .__add__ = (binary_operator_t)&add, .__sub__ = (binary_operator_t)&sub, .__mul__ = (binary_operator_t)&exec_mul, .__div__ = (binary_operator_t)&exec_div, .__eq__ = (binary_comparator_t)&equal, .__gt__ = (binary_comparator_t)&great_than, .__lt__ = (binary_comparator_t)&lower_than}, .x = 0};

Class *Char = (Class *)&_description;
