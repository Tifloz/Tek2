/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_NANOTEKSPICE_2018_4001_HPP
#define OOP_NANOTEKSPICE_2018_4001_HPP

#include "IComponent.hpp"
#include <iostream>

namespace nts {
    class C4001 : public IComponent {
        public:
        C4001(std::string const &value);

        ~C4001() override;

        nts::Tristate compute(size_t pin_num_this = 1) override;

        void setLink(size_t pin_num_this, nts::IComponent &component,
            size_t pin_num_target
        ) override;

        void dump() const override;
    };
}
#endif //OOP_NANOTEKSPICE_2018_4001_HPP
