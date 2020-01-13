/*
** EPITECH PROJECT, 2022
** cppd012018
** File description:
** Created by Jonathan Lefebvre,
*/
#include <string.h>
#include "object.h"
#include "player.h"

Object *va_new(Class *class, va_list *ap)
{
    Object *value = NULL;

    if (!class || !class->__size__ || !class->__ctor__)
        return (NULL);
    value = malloc(class->__size__);
    if (!value)
        raise("Out of memory");
    if (!memcpy(value, class, class->__size__))
        raise("Error at initialization of the class");
    class->__ctor__(value, ap);
    return (value);
}

Object *new(Class *class, ...)
{
    Object *value = NULL;
    va_list args;

    if (!class || !class->__ctor__ || !class->__size__)
        return (NULL);
    va_start(args, class);
    value = malloc(class->__size__);
    if (!value)
        raise("Out of memory");
    if (!memcpy(value, class, class->__size__))
        raise("Error at initialization of the class");
    class->__ctor__(value, &args);
    va_end(args);

    return (value);
}

void delete(Object *ptr)
{
    if (ptr)
        if (((Class *)ptr)->__dtor__)
            ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}