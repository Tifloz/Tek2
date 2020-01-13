/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#include "../../include/4001.hpp"

nts::C4001::C4001(std::string const &value)
{
    (void)value;
}

nts::C4001::~C4001()
{
}

nts::Tristate nts::C4001::compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED);
}

void nts::C4001::setLink(size_t pin_num_this, nts::IComponent &component,
    size_t pin_num_target
)
{
    (void)pin_num_this;
    (void)component;
    (void)pin_num_target;
}

void nts::C4001::dump() const
{
}
