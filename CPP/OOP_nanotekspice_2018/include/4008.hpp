/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_NANOTEKSPICE_2018_4008_HPP
#define OOP_NANOTEKSPICE_2018_4008_HPP

#include "IComponent.hpp"
#include <iostream>

namespace nts {
    class C4008 : public IComponent {
        public:
        C4008(std::string const &value);

        ~C4008() override;

        nts::Tristate compute(size_t pin_num_this = 1) override;

        void setLink(size_t pin_num_this, nts::IComponent &component,
            size_t pin_num_target
        ) override;

        void dump() const override;
    };
}
#endif //OOP_NANOTEKSPICE_2018_4008_HPP
