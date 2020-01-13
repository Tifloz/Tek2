/*
** EPITECH PROJECT, 2022
** cppd012018
** File description:
** Created by Jonathan Lefebvre,
*/

#include <stdio.h>
#include <memory.h>
#include "point.h"
#include "vertex.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

/*
static bool verif_type(const VertexClass *a, const VertexClass *b)
{
    if (a && b && a->base.__name__ && b->base.__name__)
        return strcmp(a->base.__name__, b->base.__name__) != 0 ? false : true;
    return false;
}
*/
static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static const char *string(VertexClass *this)
{
    int size = 0;
    char *str = NULL;

    if (!this)
        return NULL;
    size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->y,
        this->z);
    str = malloc((size + 1) * sizeof(char));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static const Object *sub(const VertexClass *a, const VertexClass *b)
{
    if (a && b)
        return new(Vertex, a->x - b->x, a->y - b->y, a->z - b->z);
    return (NULL);
}

static const Object *add(const VertexClass *a, const VertexClass *b)
{
    if (a && b)
        return new(Vertex, a->x + b->x, a->y + b->y, a->z + b->z);
    return NULL;
}

static const Object *multi(const VertexClass *a, const VertexClass *b)
{
    if (a && b)
        return new(Vertex, a->x * b->x, a->y * b->y, a->z * b->z);
    return NULL;
}

static const Object *exec_div(const VertexClass *a, const VertexClass *b)
{
    int a_number = 0;
    int b_number = 0;
    int c_number = 0;

    if (!a || !b)
        return NULL;
    a_number = b->x == 0 ? 0 : a->x / b->x;
    b_number = b->y == 0 ? 0 : a->y / b->y;
    c_number = b->z == 0 ? 0 : a->z / b->z;
    return new(Vertex, a_number, b_number, c_number);
}

static bool if_egal(const VertexClass *a, const VertexClass *b)
{
    if (a && b && a->x == b->x && a->y == b->y && a->z == b->z)
        return true;
    return false;
}

static bool greater_than(const VertexClass *a, const VertexClass *b)
{
    if (a && b && a->x > b->x && a->y > b->y && a->z > b->z)
        return true;
    return false;
}

static bool less_than(const VertexClass *a, const VertexClass *b)
{
    if (a && b && a->x < b->x && a->y < b->y && a->z < b->z)
        return true;
    return false;
}


static VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&string,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&multi,
        .__div__ = (binary_operator_t)&exec_div,
        .__eq__ = (binary_comparator_t)&if_egal,
        .__gt__ = (binary_comparator_t)&greater_than,
        .__lt__ = (binary_comparator_t)&less_than
    },
    .x = 0,
    .y = 0,
    .z = 0
};

Class   *Vertex = (Class *)&_description;

