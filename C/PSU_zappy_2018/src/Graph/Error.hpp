/*
** EPITECH PROJECT, 2019
** cpp_arcade
** File description:
** Error
*/

#ifndef ERROR_H
#define ERROR_H

#include <string>

class ZappyError : public std::exception
{
public:
    ZappyError(const std::string &message = "Error") { _msg = message; };

    const char *what() const throw() { return _msg.c_str(); }

private:
    std::string _msg;
};

#endif
