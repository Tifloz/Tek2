/*
** EPITECH PROJECT, 2022
** 202unsold_2018
** File description:
** Created by Florian Louvet,
*/

#ifndef INC_202UNSOLD_2018_PRINTER_HPP
#define INC_202UNSOLD_2018_PRINTER_HPP

class Printer {
    public:
    Printer();

    virtual ~Printer();

    void Usage();

    void Error();

    void Separator();

    void Final(double n, double sd, double a, double root, double h);
};

#endif //INC_202UNSOLD_2018_PRINTER_HPP
