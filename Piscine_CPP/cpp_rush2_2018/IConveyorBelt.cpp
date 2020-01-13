/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

#include "IConveyorBelt.hpp"
#include "Object.hpp"
#include "LittlePony.hpp"

Object *IConveyorBelt::getObject() const
{
    return object;
}

void IConveyorBelt::setObject(Object *object)
{
    IConveyorBelt::object = object;
}

void IConveyorBelt::in()
{
    if (!output && !input)
        std::cout << "ERROR: the Conveyor Belt is not linked" << std::endl;
    if ( object)
        std::cout << "Your Conveyor is not empty" << std::endl;
    else if (!input)
    {
        auto *new_pony = new LittlePony();
        object = new_pony;
         std::cout << "You received a new toy" << std::endl;
    } else {
        if (input->object){
            object = input->object;
            input->object = nullptr;
            std::cout << "You received a toy from the previous ConveyorBelt" << std::endl;
        } else {
            std::cout << "There is none toy to send to you" << std::endl;
        }
    }
}

void IConveyorBelt::out()
{
    if (!output && !input)
        std::cout << "ERROR: the Conveyor Belt is not linked" << std::endl;
    else if (!output) {
        if (object != nullptr) {
            delete (object);
            std::cout << "The object have been send to the santa Claus"
                << std::endl;
        } else {
            std::cout << "There is none object on the Conveyor Belt"
                << std::endl;
        }
    }else {
        if (output->object)
        {
            std::cout << "There is already an object on the newt ConveyorBelt" << std::endl;
        } else {
            output->object = object;
            output->object = nullptr;
            std::cout << "The object have been sent to the next ConveyorBelt" << std::endl;
        }
    }
}

IConveyorBelt::IConveyorBelt(IConveyorBelt *input, IConveyorBelt *output) :
input(input)
, output(output)
{
}

IConveyorBelt *IConveyorBelt::getInput() const
{
    return input;
}

IConveyorBelt *IConveyorBelt::getOutput() const
{
    return output;
}