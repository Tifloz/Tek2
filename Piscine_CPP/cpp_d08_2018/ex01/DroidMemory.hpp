/*
** EPITECH PROJECT, 2022
** cpp_d08_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D08_2018_DROIDMEMORY_HPP
#define CPP_D08_2018_DROIDMEMORY_HPP

#include <iostream>

class DroidMemory {
    public:
    DroidMemory();

    ~DroidMemory();

    size_t getFingerPrint() const;

    size_t getExp() const;

    void setFingerPrint(size_t fingerprint);

    void setExp(size_t exp);

    DroidMemory &operator=(const DroidMemory &droid);

    DroidMemory &operator<<(const DroidMemory &right);

    DroidMemory const &operator>>(DroidMemory &right) const;

    DroidMemory &operator+=(const DroidMemory &right);

    DroidMemory &operator+=(size_t exp);

    DroidMemory &operator+(const DroidMemory &right) const;

    DroidMemory &operator+(size_t exp) const;

    private:
    size_t FingerPrint;
    size_t Exp;
};

std::ostream &operator<<(std::ostream &os, DroidMemory const &droid);

#endif //CPP_D08_2018_DROIDMEMORY_HPP
