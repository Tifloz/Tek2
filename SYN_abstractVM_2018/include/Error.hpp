/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Cpp file
*/

#ifndef SYN_ABSTRACTVM_2018_ERROR_HPP
#define SYN_ABSTRACTVM_2018_ERROR_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

typedef std::string String;

class Exception : public std::exception {
    protected:
    std::string _error;

    public:
    explicit Exception(String const &error) noexcept;

    ~Exception() override;

    const char *what() const noexcept override;
};

#endif //SYN_ABSTRACTVM_2018_ERROR_HPP
