#include <utility>

/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
    this->is_working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(std::move(drug));
}

std::string KoalaNurse::readReport(std::string report)
{
    std::ifstream file;
    std::string drug;
    std::string koala;
    int pos = static_cast<int>(report.find(".report"));
    char buff;

    if (pos)
        file.open(report.c_str(), std::fstream::in);
    if (file) {
        while (!file.eof())
            ((buff = (char)file.get()) != -1) ? drug += buff : nullptr;
    }
    koala = report.substr(0, static_cast<unsigned long>(pos));
    if (!koala.empty() && !drug.empty())
        std::cout << "Nurse " << this->id << " Kreog! Mr." << koala
            << ": needs a " << drug << "!" << std::endl;
    else
        return ("");
    if (file)
        file.close();
    return (drug);
}

void KoalaNurse::timeCheck()
{
    if (this->is_working)
        std::cout << "Nurse " << this->id
            << ": Time to go home to my  eucalyptus  forest!" << std::endl;
    else
        std::cout << "Nurse " << this->id << ": Time to get to work!"
            << std::endl;
    this->is_working = !this->is_working;
}