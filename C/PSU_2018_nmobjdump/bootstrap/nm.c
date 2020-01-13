/*
** EPITECH PROJECT, 2022
** PSU_2018_nmobjdump
** File description:
** Created by Florian Louvet,
*/
#include <unistd.h>
const int tata = 11;

void toto()
{
    write(1, "Test\n", 5);
}

int main()
{
    int ac = 22323;
    ac++;
    toto();
    return (0);
}