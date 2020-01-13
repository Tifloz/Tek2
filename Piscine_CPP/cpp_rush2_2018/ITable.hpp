/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/


#ifndef DAY_ONE_CPP_ITABLE_HPP
#define DAY_ONE_CPP_ITABLE_HPP

#include "Object.hpp"

class ITable {
    protected:
        Object *array[10]{};
        ITable() = default;
        ~ITable();
    public:
        int GetSpace();
        void AddObject(Object *object);
        Object *GetObject(int n);
        Object ** GetArray();
        void DeleteObject(int n);

};

#endif //DAY_ONE_CPP_ITABLE_HPP
