/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/
#include "ITable.hpp"

int ITable::GetSpace()
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}

void ITable::AddObject(Object *object)
{
    int i = 0;

    while (array[i])
        i++;
    if (i < 10)
        array[i] = object;
}

Object *ITable::GetObject(int n)
{
    if (n > 9 || n < 0)
        return nullptr;
    return array[n];
}

Object **ITable::GetArray()
{
    return array;
}

void ITable::DeleteObject(int n)
{
    if (n > 9 || n < 0)
        return;
    if (array[n]) {
        array[n] = nullptr;
    }

}

ITable::~ITable()
{
    int i = 0;

    while (array[i]) {
        delete (array[i]);
        i++;
    }
}

