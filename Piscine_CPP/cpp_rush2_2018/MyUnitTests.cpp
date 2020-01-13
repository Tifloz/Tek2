/*
** EPITECH PROJECT, 2019
** cpp_rush2_2018
** File description:
** MyUnitTests Part I and Part II
*/
#include "Object.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

Object **MyUnitTests()
{
    Object **array;
    try {
        array = new Object *[2];
        array[0] = new Teddy;
        array[1] = new LittlePony;
    } catch (std::bad_alloc &e) {
        std::cerr << "Unable to allocate." << std::endl;
        return nullptr;
    }
    return array;
}

Object *MyUnitTests(Object **pObject)
{
    Teddy *Bear = nullptr;
    GiftPaper *GiftPaperWithXmasTrees = nullptr;
    Box *BoxWithBigBow = nullptr;

    if (!pObject) {
        std::cerr << "Invalid list of objects passed as argument." << std::endl;
        return nullptr;
    }
    for (int i = 0; i != 3; ++i) {
        if (pObject[i]->getClassName() == "Teddy") {
            Bear = dynamic_cast<Teddy *>(pObject[i]);
        } else if (pObject[i]->getClassName() == "GiftPaper") {
            GiftPaperWithXmasTrees = dynamic_cast<GiftPaper *>(pObject[i]);
        } else if (pObject[i]->getClassName() == "Box") {
            BoxWithBigBow = dynamic_cast<Box *>(pObject[i]);
        }
    }
    BoxWithBigBow->openMe();
    BoxWithBigBow->warpMeThat(Bear);
    BoxWithBigBow->closeMe();
    GiftPaperWithXmasTrees->openMe();
    GiftPaperWithXmasTrees->warpMeThat(BoxWithBigBow);
    GiftPaperWithXmasTrees->closeMe();
    return GiftPaperWithXmasTrees;
}
