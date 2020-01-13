/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/


#ifndef DAY_ONE_CPP_ICONVEYORBELT_HPP
#define DAY_ONE_CPP_ICONVEYORBELT_HPP

#include "Object.hpp"

class IConveyorBelt {
    protected:
        Object *object {};
        IConveyorBelt *input;
        IConveyorBelt *output;
        explicit IConveyorBelt(IConveyorBelt *input = nullptr, IConveyorBelt *output = nullptr);
        ~IConveyorBelt() = default;
    public:
	    IConveyorBelt *getInput() const;
	    IConveyorBelt *getOutput() const;
	    void in();
        void out();
        Object *getObject() const;
        void setObject(Object *object);
};

#endif //DAY_ONE_CPP_ICONVEYORBELT_HPP
