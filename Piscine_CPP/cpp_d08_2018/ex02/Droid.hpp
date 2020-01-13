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
    #include "DroidMemory.hpp"

class Droid {
    public:
    Droid(std::string serial);

    Droid(const Droid &droid);

    ~Droid();

    DroidMemory *getBattleData();

    void setBattleData(DroidMemory *data);

    std::string getId() const;

    size_t getEnergy() const;

    size_t getAttack() const;

    size_t getToughness() const;

    std::string *getStatus() const;

    void setId(std::string id);

    void setEnergy(size_t energy);

    void setStatus(std::string *status);

    Droid &operator=(const Droid &droid);

    bool operator==(const Droid &droid) const;

    bool operator!=(const Droid &droid) const;

    Droid &operator<<(size_t &energy);

    bool operator()(const std::string *task, size_t exp);

    private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
    DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &os,const Droid &droid);

#endif //CPP_D08_2018_DROID_HPP
