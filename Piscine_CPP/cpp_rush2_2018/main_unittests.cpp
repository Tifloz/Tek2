/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Mious oui la guguerre,
*/

#include "Object.hpp"
#include "Teddy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Warp.hpp"

Object *MyUnitTests(Object **);

Object **MyUnitTests();

int main()
{
    Object **pObject = MyUnitTests();
    Warp *Wrap = nullptr;

    std::cout << "[1] TEST UNITAIRE -----" << std::endl;
    std::cout << pObject[0]->getTitle() << std::endl;
    std::cout << pObject[1]->getTitle() << std::endl;
    std::cout << "[2] TEST UNITAIRE -----" << std::endl;
    Object *Bear = new Teddy();
    Object *BoxWithBigBow = new Box();
    Object *GiftPaperWithXmasTrees = new GiftPaper();
    Object *tab[3];
    tab[0] = Bear;
    tab[1] = BoxWithBigBow;
    tab[2] = GiftPaperWithXmasTrees;
    Object *GifToOpen = MyUnitTests(tab);
    Wrap = dynamic_cast<Warp *>(GifToOpen);
    std::cout << std::endl;
    std::cout << "Damn those Christmas tress on this " << Wrap->getClassName()
        << " are so sweet!" << std::endl;
    Wrap->openMe();
    std::cout << "Look at this " << Wrap->getObject()->getClassName()
        << " with this big bow at the top!!" << std::endl;
    Wrap = dynamic_cast<Warp *>(Wrap->getObject());
    Wrap->openMe();
    std::cout << "Awwwww this " << Wrap->getObject()->getClassName()
        << " is so cuuuute" << std::endl;
    return 0;
}
