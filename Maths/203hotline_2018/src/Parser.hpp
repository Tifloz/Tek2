/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Created by Florian Louvet,
*/
#ifndef INC_202UNSOLD_PARSER_HPP
#define INC_202UNSOLD_PARSER_HPP

class Parser {
    public:
    Parser();

    virtual ~Parser();

    void Launch(int ac, char **av);

    bool IsANumber(char *str);
};

#endif //INC_202UNSOLD_PARSER_HPP
