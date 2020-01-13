/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void)
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor(void) = default;

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool value)
{
    this->_stability = value;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor)
{
    this->_coreReactor = coreReactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}

WarpSystem::Core::~Core(void) = default;
