/*
** EPITECH PROJECT, 2022
** cpp_rush2_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_RUSH2_2018_XMLWRITER_HPP
#define CPP_RUSH2_2018_XMLWRITER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class XmlWriter {
    public:
    bool open(const std::string);

    void close();

    bool exists(const std::string);

    void writeOpenTag(const std::string);

    void writeCloseTag();

    void writeStartElementTag(const std::string);

    void writeEndElementTag();

    void writeAttribute(const std::string, const std::string);

    void writeString(const std::string);

    private:
    std::ofstream outFile;
    int indent;
    int openTags;
    int openElements;
    std::vector<std::string> tempOpenTag;
    std::vector<std::string> tempElementTag;
};

#endif //CPP_RUSH2_2018_XMLWRITER_HPP
