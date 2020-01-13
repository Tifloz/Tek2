/*
** EPITECH PROJECT, 2022
** cpp_d06_2018
** File description:
** Created by Florian Louvet,
*/
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->is_working = false;
    std::cout << "Dr." << name << ": I’m Dr." << name << "! How do you kreog?"
        << std::endl;
}

KoalaDoctor::~KoalaDoctor() = default;

void KoalaDoctor::diagnose(SickKoala *koala)
{
    int i = rand() % 5;
    std::string filename = koala->getName() + ".report";
    std::ofstream output(filename.c_str());
    std::string drugs[5] = {"mars", "Buronzand", "Viagra", "Extasy",
        "Eucalyptus leaf"};

    std::cout << "Dr." << name << ": So what’s goerking you Mr."
        << koala->getName() << " ?" << std::endl;
    koala->poke();
    output << drugs[i];
}

void KoalaDoctor::timeCheck()
{
    if (this->is_working)
        std::cout << "Dr." << this->name
            << ": Time to go home to my eucalyptus forest" << std::endl;
    else
        std::cout << "Dr." << this->name << ": Time to get to work!"
            << std::endl;
    this->is_working = !this->is_working;
}