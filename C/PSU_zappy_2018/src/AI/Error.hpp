/*
** EPITECH PROJECT, 2019
** psu_zappy_2018
** File description:
** Error
*/

#ifndef ERROR_H
#define ERROR_H

#include <string>

class AIError : public std::exception
{
public:
    AIError(const std::string &message = "Error") { _msg = message; };

    const char *what() const throw() { return _msg.c_str(); }

private:
    std::string _msg;
};

#endif
