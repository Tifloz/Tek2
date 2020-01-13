/*
** EPITECH PROJECT, 2022
** cpp_d08_2018
** File description:
** Created by Florian Louvet,
*/
#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Exp(0)
{
    this->FingerPrint = random();
}

DroidMemory::~DroidMemory() = default;

size_t DroidMemory::getFingerPrint() const
{
    return (this->FingerPrint);
}

size_t DroidMemory::getExp() const
{
    return (this->Exp);
}

void DroidMemory::setFingerPrint(size_t fingerprint)
{
    this->FingerPrint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    this->Exp = exp;
}

DroidMemory &DroidMemory::operator=(const DroidMemory &droid)
{
    this->FingerPrint = droid.FingerPrint;
    this->Exp = droid.Exp;
    return (*this);
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &right)
{
    this->Exp = this->Exp + right.Exp;
    this->FingerPrint = this->FingerPrint ^ right.FingerPrint;
    return (*this);
}

DroidMemory const &DroidMemory::operator>>(DroidMemory &right) const
{
    right.Exp = this->Exp + right.Exp;
    right.FingerPrint = this->FingerPrint ^ right.FingerPrint;
    return (*this);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &right)
{
    *this << right;
    return (*this);
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->Exp = this->Exp + exp;
    this->FingerPrint = this->FingerPrint ^ exp;
    return (*this);
}

DroidMemory &DroidMemory::operator+(const DroidMemory &right) const
{
    auto *memory = new DroidMemory();
    memory->Exp = this->Exp + right.Exp;
    memory->FingerPrint = this->FingerPrint ^ right.FingerPrint;
    return (*memory);
}

DroidMemory &DroidMemory::operator+(size_t exp) const
{
    auto *memory = new DroidMemory();
    memory->Exp = this->Exp + exp;
    memory->setFingerPrint(this->FingerPrint ^ exp);
    return (*memory);
}

std::ostream &operator<<(std::ostream &os, DroidMemory const &droid)
{
    return (os << "DroidMemory '" << droid.getFingerPrint() << "', "
        << droid.getExp());
}