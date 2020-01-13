/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#include "PapaXmasConveyorBelt.hpp"

IConveyorBelt *createConveyorBelt()
{
    IConveyorBelt *new_conveyor = new PapaXmasConveyorBelt;
    return new_conveyor;
}