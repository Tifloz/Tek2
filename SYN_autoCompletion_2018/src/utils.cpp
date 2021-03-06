/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include <vector>
#include <string>
#include "utils.hpp"

Utils::Utils() = default;

Utils::~Utils() = default;

std::vector <std::string> Utils::Split(const std::string &s,
    const std::string &delimiter
)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector <std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

std::string &ltrim(std::string &str, const std::string &chars
)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string &rtrim(std::string &str, const std::string &chars
)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string &Utils::trim(std::string str, const std::string &chars
)
{
    return ltrim(rtrim(str, chars), chars);
}