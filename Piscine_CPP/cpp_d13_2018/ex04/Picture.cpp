/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}

Picture::~Picture() = default;

bool Picture::getPictureFromFile(const std::string &fileName)
{
    std::ifstream file;
    std::string data;
    char buff;

    file.open(fileName.c_str(), std::fstream::in);
    if (file) {
        while (!file.eof()) {
            buff = (char)file.get();
            if (buff != -1)
                data += buff;
        }
    } else {
        this->data = "ERROR";
        return false;
    }
    this->data = data;
    file.close();
    return true;
}

Picture &Picture::operator=(Picture const &picture)
{
    this->data = picture.data;
    return *this;
}
