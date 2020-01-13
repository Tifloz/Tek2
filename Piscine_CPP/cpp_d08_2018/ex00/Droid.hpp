/*
** EPITECH PROJECT, 2022
** cpp_d08_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D08_2018_DROID_HPP
#define CPP_D08_2018_DROID_HPP

#include <iostream>
#include <string>

class Droid {
    public:
    Droid(std::string serial = "");

    Droid(Droid const &droid);

    ~Droid();

    std::string getId() const;

    size_t getEnergy() const;

    size_t getAttack() const;

    size_t getToughness() const;

    std::string *getStatus() const;

    void setId(std::string id);

    void setEnergy(size_t energy);

    void setStatus(std::string *status);

    Droid &operator=(Droid const &droid);

    bool operator==(Droid const &droid) const;

    bool operator!=(Droid const &droid) const;

    Droid &operator<<(size_t &energy);

    private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
};

std::ostream &operator<<(std::ostream &os, Droid const &droid);

#endif //CPP_D08_2018_DROID_HPP
