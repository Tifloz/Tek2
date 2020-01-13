/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Created by Valentin Maeght,
*/

#ifndef ARCADE_POSITION_HPP
#define ARCADE_POSITION_HPP
class Position {
    public:
        int x;
        int y;
        int z;
        Position(int x, int y, int z = 0);
        ~Position() = default;
};
#endif //ARCADE_POSITION_HPP
