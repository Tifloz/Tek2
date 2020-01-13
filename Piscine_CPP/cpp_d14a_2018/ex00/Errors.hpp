/*
** EPITECH PROJECT, 2022
** cpp_d14a_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <iostream>
#include <stdexcept>

class NasaError : public std::exception {
    public:
    NasaError(const std::string &message,
        const std::string &component = "Unknown"
    );

    ~NasaError();

    std::string const &getComponent() const;

    char const *what() const throw();

    private:
    std::string _component;
    std::string _message;
};

class MissionCriticalError : public NasaError {
    public:
    MissionCriticalError(const std::string &message,
        std::string const &component = "Unknown"
    );
};

class LifeCriticalError : NasaError {
    public:
    LifeCriticalError(const std::string &message,
        std::string const &component = "Unknown"
    );
};

class UserError : NasaError {
    public:
    UserError(const std::string &message,
        std::string const &component = "Unknown"
    );
};

class CommunicationError : NasaError {
    public:
    explicit CommunicationError(const std::string &message);
};

#endif
