/*
** EPITECH PROJECT, 2022
** cpp_d14a_2018
** File description:
** Created by Florian Louvet,
*/
#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component)
    : _message(message), _component(component)
{
}

const std::string &NasaError::getComponent() const
{
    return this->_component;
}

char const *NasaError::what() const noexcept
{
    return this->_message.c_str();
}

NasaError::~NasaError() = default;

CommunicationError::CommunicationError(const std::string &message) : NasaError(
    message, "CommunicationDevice")
{
}

MissionCriticalError::MissionCriticalError(const std::string &message,
    const std::string &component
) : NasaError(message, component)
{
}

UserError::UserError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message,
    const std::string &component
) : NasaError(message, component)
{
}
