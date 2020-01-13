/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_NANOTEKSPICE_2018_COMPONENTS_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTS_HPP

#include <iostream>
#include <map>
#include "IComponent.hpp"

namespace nts {
    class Components {
        public:
        Components();

        virtual ~Components();

        IComponent *createComponent(const std::string &type,
            const std::string &value
        );

        private:
        nts::IComponent *create2716(const std::string &value) const;

        nts::IComponent *create4001(const std::string &value) const;

        nts::IComponent *create4008(const std::string &value) const;

        nts::IComponent *create4011(const std::string &value) const;

        nts::IComponent *create4013(const std::string &value) const;

        nts::IComponent *create4017(const std::string &value) const;

        nts::IComponent *create4030(const std::string &value) const;

        nts::IComponent *create4040(const std::string &value) const;

        nts::IComponent *create4069(const std::string &value) const;

        nts::IComponent *create4071(const std::string &value) const;

        nts::IComponent *create4081(const std::string &value) const;

        nts::IComponent *create4094(const std::string &value) const;

        nts::IComponent *create4514(const std::string &value) const;

        nts::IComponent *create4801(const std::string &value) const;
    };
}
#endif //OOP_NANOTEKSPICE_2018_COMPONENTS_HPP
