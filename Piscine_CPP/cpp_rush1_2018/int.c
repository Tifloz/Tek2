/*
** EPITECH PROJECT, 2022
** cppd012018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "int.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this)
        this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static const char *string(IntClass *this)
{
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Int (%d)>", this->x);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Int (%d)>", this->x);
    return (str);
}

static const Object *sub(const IntClass *a, const IntClass *b)
{
    if (a && b)
        return new(Int, a->x - b->x);
    return NULL;
}

static const Object *add(const IntClass *a, const IntClass *b)
{
    if (a && b)
        return new(Int, a->x + b->x);
    return NULL;
}

static const Object *exec_mul(const IntClass *a, const IntClass *b)
{
    if (a && b)
        return new(Int, a->x * b->x);
    return NULL;
}

static const Object *exec_div(const IntClass *a, const IntClass *b)
{
    int value = 0;
    if (!a || !b)
        return NULL;
    value = b->x == 0 ? 0 : a->x / b->x;
    return new(Int, value);
}

static bool equal(const IntClass *a, const IntClass *b)
{
    return a && b && a->x == b->x ? true : false;
}

static bool great_than(const IntClass *a, const IntClass *b)
{
    return a && b && a->x > b->x ? true : false;
}

static bool lower_than(const IntClass *a, const IntClass *b)
{
    return a && b && a->x < b->x ? true : false;
}

static IntClass _description = {
    {.__size__ = sizeof(IntClass), .__name__ = "Int", .__ctor__ = (ctor_t)&Int_ctor, .__dtor__ = (dtor_t)&Int_dtor, .__str__ = (to_string_t)&string, .__add__ = (binary_operator_t)&add, .__sub__ = (binary_operator_t)&sub, .__mul__ = (binary_operator_t)&exec_mul, .__div__ = (binary_operator_t)&exec_div, .__eq__ = (binary_comparator_t)&equal, .__gt__ = (binary_comparator_t)&great_than, .__lt__ = (binary_comparator_t)&lower_than}, .x = 0};

Class *Int = (Class *)&_description;
