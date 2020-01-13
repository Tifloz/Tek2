/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static const char *string(PointClass *this)
{
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return (str);
}

static const Object *sub(const PointClass *a, const PointClass *b)
{
    if (a && b)
        return new(Point, a->x - b->x, a->y - b->y);
    return NULL;
}

static const Object *add(const PointClass *a, const PointClass *b)
{
    if (a && b)
        return new(Point, a->x + b->x, a->y + b->y);
    return NULL;
}

static const Object *multi(const PointClass *a, const PointClass *b)
{
    if (a && b)
        return new(Point, a->x * b->x, a->y * b->y);
    return NULL;
}

static const Object *exec_div(const PointClass *a, const PointClass *b)
{
    int a_number = 0;
    int b_number = 0;

    if (a && b) {
        a_number = b->x == 0 ? 0 : a->x / b->x;
        b_number = b->y == 0 ? 0 : a->y / b->y;
        return new(Point, a_number, b_number);
    }
    return NULL;
}

static bool if_egal(const PointClass *a, const PointClass *b)
{
    if (a && b && a->x == b->x && a->y == b->y)
        return true;
    return false;
}

static bool greater_than(const PointClass *a, const PointClass *b)
{
    if (a && b && a->x > b->x && a->y > b->y)
        return true;
    return false;
}

static bool less_than(const PointClass *a, const PointClass *b)
{
    if (a && b && a->x < b->x && a->y < b->y)
        return true;
    return false;
}

static PointClass _description = {
    {.__size__ = sizeof(PointClass), .__name__ = "Point", .__ctor__ = (ctor_t)&Point_ctor, .__dtor__ = (dtor_t)&Point_dtor, .__str__ = (to_string_t)&string, .__add__ = (binary_operator_t)&add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&multi, .__div__ = (binary_operator_t)&exec_div, .__eq__ = (binary_comparator_t)&if_egal, .__gt__ = (binary_comparator_t)&greater_than, .__lt__ = (binary_comparator_t)&less_than}, .x = 0, .y = 0};

Class *Point = (Class *)&_description;

