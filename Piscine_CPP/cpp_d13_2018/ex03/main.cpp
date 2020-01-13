/*
** EPITECH PROJECT, 2022
** cpp_d13_2018
** File description:
** Created by Florian Louvet,
*/
#include  <iostream>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
#include <memory>

int main()
{
    std::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "alien.txt"));
    b->speak("To the code , and  beyond  !!!!!!!!");
    w->speak("There's a snake  in my boot.");
    t->speak("the  claaaaaaw");
}