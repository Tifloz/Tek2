/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Cpp file
*/


#include "../include/IOperand.hpp"
#include "../include/Factory.hpp"
#include "../include/Parser.hpp"
#include "../include/Error.hpp"
#include "../include/Interpretor.hpp"

typedef void(Interpretor::*ptr)(IOperand *);

std::map<std::string, ptr> init_map()
{
    std::map<std::string, ptr> map;

    map["push"] = &Interpretor::push;
    map["pop"] = &Interpretor::pop;
    map["clear"] = &Interpretor::clear;
    map["dup"] = &Interpretor::dup;
    map["swap"] = &Interpretor::swap;
    map["dump"] = &Interpretor::dump;
    map["assert"] = &Interpretor::assert;
    map["add"] = &Interpretor::add;
    map["sub"] = &Interpretor::sub;
    map["mul"] = &Interpretor::mul;
    map["div"] = &Interpretor::div;
    map["mod"] = &Interpretor::mod;
    map["load"] = &Interpretor::load;
    map["store"] = &Interpretor::store;
    map["print"] = &Interpretor::print;
    map["exit"] = &Interpretor::exit;
    return (map);
}

eOperandType getType(const std::string &str)
{
    eOperandType type = NONE;

    (str == "int8") ? type = INT8 : (str == "int16") ? type = INT16 :
        (str == "int32") ? type = INT32 : (str == "float") ? type = FLOAT :
            (str == "double") ? type = DOUBLE :
                (str == "bigdecimal") ? type = BIGDECIMAL : type = NONE;

    return type;
}

int loop(const std::vector<std::smatch> &v)
{
    Interpretor I;
    Factory Facto;
    int i;
    std::map<std::string, ptr> map = init_map();

    for (i = 0; i < (int)v.size(); i++) {
        if (v[i].str(1) == "exit")
            break;
        if (map.find(v[i].str(1)) != map.end())
            (I.*map[v[i].str(1)])(
                Factory::createOperand(getType(v[i].str(2)), v[i].str(3)));
        else
            throw (Exception("command not found"));
    }
    if (i == (int)v.size())
        throw (Exception("Exit command not found"));
    return (0);
}

int main(int ac, char **av)
{
    Parser parse;

    try {
        if (ac == 1)
            parse.readLine();
        else if (ac == 2)
            parse.readFile(av[1]);
        else
            std::cout << "USAGE:\n\tabstractVM [file]" << std::endl;
        parse.parse_command();
        loop(parse.getCommand());
    } catch (Exception const &error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return (84);
    }
    return (0);
}