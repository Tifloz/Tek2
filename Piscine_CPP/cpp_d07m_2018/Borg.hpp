/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07M_2018_BORG_HPP
#define CPP_D07M_2018_BORG_HPP

namespace Borg
{
    class Ship;
}

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Borg {
    class Ship {
        public:
        Ship(int  weaponFrequency = 20, short  repair = 3);

        ~Ship();

        void setupCore(WarpSystem::Core *core);

        void checkCore();

        bool move(int warp, Destination d);

        bool move(int warp);

        bool move(Destination d);

        bool move();

        int getShield(void);

        void setShield(int shield);

        int getWeaponFrequency();

        void setWeaponFrequency(int frequency);

        short getRepair();

        void setRepair(short repair);

        void fire(Federation::Starfleet::Ship *target);

        void fire(Federation::Ship *target);

        void repair();

        private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
        int _shield;
        int _weaponFrequency;
        short _repair;
    };
};

#endif //CPP_D07M_2018_BORG_HPP
