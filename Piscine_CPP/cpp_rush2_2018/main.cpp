#include "Object.hpp"
#include "PapaXmasTable.hpp"
#include "xmlWriter.hpp"
#include "Toy.hpp"
#include "LittlePony.hpp"
#include "IConveyorBelt.hpp"
#include "PapaXmasConveyorBelt.hpp"

/*
** EPITECH PROJECT, 2022
** day-one-cpp
** File description:
** Created by Valentin MAEGHT,
*/

void writeXml(PapaXmasConveyorBelt gift, const std::string fileName)
{
    XmlWriter xml;

    if (xml.open(fileName)) {
        xml.writeOpenTag("Main");
        xml.writeOpenTag("Gift");
        xml.writeStartElementTag("Info");
        xml.writeAttribute("data", "\"ClassName\"");
        xml.writeString(gift.getObject()->getClassName());
        xml.writeEndElementTag();
        xml.writeStartElementTag("Info");
        xml.writeAttribute("data", "\"Is taken\"");
        xml.writeString((gift.getObject()->isTaken() ? "true" : "false"));
        xml.writeEndElementTag();
        xml.writeStartElementTag("Info");
        xml.writeAttribute("data", "\"Is wrapped\"");
        xml.writeString((gift.getObject()->isWarp() ? "true" : "false"));
        xml.writeEndElementTag();
        xml.writeCloseTag();
        xml.writeCloseTag();
        xml.close();
    }
}

void readXml(IConveyorBelt gift)
{
    (void)gift;
}

int main()
{
    Object *objectTest = new Toy("mon cul");
    PapaXmasTable table;
    const std::string value("lool.xml");
    PapaXmasConveyorBelt testa;

    table.AddObject(objectTest);
    table.DeleteObject(0);
    std::cout << table.GetSpace() << std::endl;
    testa.setObject(objectTest);
    writeXml(testa, value);
    return 0;
}