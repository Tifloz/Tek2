/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef SYN_AUTOCOMPLETION_2018_UTILS_HPP
#define SYN_AUTOCOMPLETION_2018_UTILS_HPP

#include <vector>
#include <string>

class Utils {
    public:
    virtual ~Utils();

    Utils();

    std::vector<std::string> Split(const std::string &s,
        const std::string &delimiter
    );

    std::string &trim(std::string str, const std::string &chars = "\t\n\v\f\r "
    );
};

#endif //SYN_AUTOCOMPLETION_2018_UTILS_HPP
