/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP

#include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
        virtual ~IComponent() = default;

        public:
        virtual nts::Tristate compute(size_t this_pin = 1) = 0;

        virtual void setLink(std::size_t pin, nts::IComponent &component,
            size_t pin_target
        ) = 0;

        virtual void dump() const = 0;
    };
}
#endif //OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP
