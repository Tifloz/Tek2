/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#include <4008.hpp>

#include "4008.hpp"

nts::C4008::C4008(std::string const &value)
{
    (void)value;
}

nts::C4008::~C4008() = default;

nts::Tristate nts::C4008::compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED);
}

void nts::C4008::setLink(size_t pin_num_this, nts::IComponent &component,
    size_t pin_num_target
)
{
    (void)pin_num_this;
    (void)component;
    (void)pin_num_target;
}

void nts::C4008::dump() const
{
}
