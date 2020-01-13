/*
** EPITECH PROJECT, 2022
** cppd012018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
#include "float.h"

typedef struct {
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static const char *string(FloatClass *this)
{
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Float (%f)>", this->x);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Float (%f)>", this->x);
    return (str);
}

static const Object *sub(const FloatClass *a, const FloatClass *b)
{
    if (a && b)
        return new(Float, (float)(a->x) - (float)(b->x));
    return NULL;
}

static const Object *add(const FloatClass *a, const FloatClass *b)
{
    if (a && b)
        return new(Float, a->x + b->x);
    return NULL;
}

static const Object *exec_mul(const FloatClass *a, const FloatClass *b)
{
    if (a && b)
        return new(Float, a->x * b->x);
    return NULL;
}

static const Object *exec_div(const FloatClass *a, const FloatClass *b)
{
    float value = 0;
    if (a && b) {
        value = b->x == 0 ? 0 : a->x / b->x;
        return new(Float, value);
    }
    return NULL;
}

static bool equal(const FloatClass *a, const FloatClass *b)
{
    return a && b && a->x == b->x ? true : false;
}

static bool great_than(const FloatClass *a, const FloatClass *b)
{
    return a && b && a->x > b->x ? true : false;
}

static bool lower_than(const FloatClass *a, const FloatClass *b)
{
    return a && b && a->x < b->x ? true : false;
}

static FloatClass _description = {
    {.__size__ = sizeof(FloatClass), .__name__ = "Float", .__ctor__ = (ctor_t)&Float_ctor, .__dtor__ = (dtor_t)&Float_dtor, .__str__ = (to_string_t)&string, .__add__ = (binary_operator_t)&add, .__sub__ = (binary_operator_t)&sub, .__mul__ = (binary_operator_t)&exec_mul, .__div__ = (binary_operator_t)&exec_div, .__eq__ = (binary_comparator_t)&equal, .__gt__ = (binary_comparator_t)&great_than, .__lt__ = (binary_comparator_t)&lower_than}, .x = 0};

Class *Float = (Class *)&_description;
