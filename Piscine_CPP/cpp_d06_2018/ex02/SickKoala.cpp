#include <utility>

/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = std::move(name);
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!"
        << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str != "Buronzand")
        for (char &i : str)
            i = static_cast<char>(tolower(i));
    if (str == "mars") {
        std::cout << "Mr." << this->name << ": Mars , and it kreogs!"
            << std::endl;
        return (true);
    } else if (str == "Buronzand") {
        std::cout << "Mr." << this->name << ": And you'll sleep right away!"
            << std::endl;
        return (true);
    } else {
        std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
        return (false);
    }
}

void SickKoala::overDrive(std::string str)
{
    std::string after = "1337!";
    std::string before = "Kreog!";
    int val;

    while ((val = static_cast<int>(str.find(before, 0))) != -1)
        str.replace(static_cast<unsigned long>(val), 6, after);
    std::cout << "Mr." << this->name << ": " << str << std::endl;
}