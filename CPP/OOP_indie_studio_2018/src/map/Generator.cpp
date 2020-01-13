/*
** EPITECH PROJECT, 2017
** Indie Studio
** File description:
** Generator.cpp
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "Generator.hpp"

int getFreeBlock()
{
    int minimum = 40;
    int range = 35;
    srand(time(NULL));
    return minimum + rand() % range;
}

int getRigidBlock(int freeBlock)
{
    int fullBlock = 121 - freeBlock;
    int minimum = round(fullBlock*15)/100;
    int maximum = round(fullBlock*30)/100;
    int range = maximum - minimum;
    srand(time(NULL));
    return minimum + rand() % range;
}

int getBreakableBlock(int freeBlock, int rigidBlock)
{
    return 121 - (freeBlock + rigidBlock);
}

int getLower(int freeBlock, int rigidBlock, int breakableBlock)
{
    int nb[3] = {freeBlock, rigidBlock, breakableBlock};
    int min = nb[0];
    for (int i = 0; i < 3; i++) {
        if (min > nb[i])
            min = nb[i];
    }
    if (min == freeBlock)
        return 0;
    else if (min == rigidBlock)
        return 1;
    return 2;
}

int decreaseFreeBlock(int freeBlock, int n)
{
    if (n == 0)
        return freeBlock - 1;
    return freeBlock;
}

int decreaseRigidBlock(int rigidBlock, int n)
{
    if (n == 1)
        return rigidBlock - 1;
    return rigidBlock;
}

int decreaseBreakableBlock(int breakableBlock, int n)
{
    if (n == 2)
        return breakableBlock - 1;
    return breakableBlock;
}

bool notRespectEquality(int n, int current, int lowerTypeBlock, int max)
{
    if (n == lowerTypeBlock) {
        if (current < max)
            return false;
        else
            return true;
    }
    return false;
}

bool noMoreStock(int freeBlock, int rigidBlock, int breakableBlock, int n)
{
    if (n == 0 && freeBlock <= 0)
        return true;
    else if (n == 1 && rigidBlock <= 0)
        return true;
    else if (n == 2 && breakableBlock <= 0)
        return true;
    return false;
}

int getMax(int freeBlock, int rigidBlock, int breakableBlock, int lowerTypeBlock)
{
    if (lowerTypeBlock == 0)
        return round(freeBlock/11);
    else if (lowerTypeBlock == 1)
        return round(rigidBlock/11);
    return round(breakableBlock/11);
}

char getChar(char number)
{
    if (number == '0')
        return ' ';
    else if (number == '1')
        return 'o';
    return '+';
}

std::string fillMap(int freeBlock, int rigidBlock, int breakableBlock, int lowerTypeBlock)
{
    std::string tab[11];
    std::string map;
    int j = 0;
    int i;
    int current = 0;
    int max = getMax(freeBlock, rigidBlock, breakableBlock, lowerTypeBlock);

    for (i = 0; i < 11; i++) {
        while (j < 11) {
            if ((i == 0 && j == 0) || (i == 0 && j == 10) || (i == 10 && j == 0) || (i == 10 && j == 10))
                tab[i] += "0";
            else {
                int n = 0 + rand() % 3;
                while (noMoreStock(freeBlock, rigidBlock, breakableBlock, n) == true
                || (i < 7 && notRespectEquality(n, current, lowerTypeBlock, max) == true))
                    n = 0 + rand() % 3;
                tab[i] += std::to_string(n);
                freeBlock = decreaseFreeBlock(freeBlock, n);
                rigidBlock = decreaseRigidBlock(rigidBlock, n);
                breakableBlock = decreaseBreakableBlock(breakableBlock, n);
                if (n == lowerTypeBlock)
                    current += 1;
            }
            j++;
        }
        j = 0;
        current = 0;
    }
    j = 0;
    for (int k = 0; k < 11; k++) {
        while (j < 11) {
            if ((k == 0 && (j == 1 || j == 9))
            || (k == 1 && (j == 0 || j == 10))
            || (k == 9 && (j == 0 || j == 10))
            || (k == 10 && (j == 1 || j == 9)))
                map += " ";
            else
                map += getChar(tab[k][j]);
            j++;
        }
        map += "\n";
        j = 0;
    }
    map[0] = '2';
    map[10] = '3';
    map[130] = '1';
    map[120] = '0';
    return map;
}

Generator::Generator(std::string name) :
_name(name),
_freeBlock(getFreeBlock()),
_rigidBlock(getRigidBlock(_freeBlock)),
_breakableBlock(getBreakableBlock(_freeBlock, _rigidBlock)),
_lowerTypeBlock(getLower(_freeBlock, _rigidBlock, _breakableBlock))
{
    std::fstream file;
    file.open(name, std::ios::out);
    file << fillMap(_freeBlock, _rigidBlock, _breakableBlock, _lowerTypeBlock);
    file.close();
}

Generator::~Generator()
{
}
