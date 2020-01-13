/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#include "PapaXmasTable.hpp"

ITable *createTable()
{
    ITable *new_table = new PapaXmasTable;
    return new_table;
}