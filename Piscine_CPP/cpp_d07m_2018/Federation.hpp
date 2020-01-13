/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07M_2018_FEDERATION_HPP
#define CPP_D07M_2018_FEDERATION_HPP

#include <string>
#include <iostream>

namespace Federation {
    namespace Starfleet {
        class Ship;

        class Captain;

        class Ensign;
    }
    class Ship;
}

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation {

    namespace Starfleet {

        class Captain {
            public:
            Captain(std::string name);

            ~Captain();

            std::string getName();

            int getAge();

            void setAge(int age);

            private:
            std::string _name;
            int _age;
        };

        class Ship {
            public:
            Ship(int length = 289, int width = 132,
                std::string name = "Entreprise", short maxWarp = 6,
                int torpedo = 0
            );

            ~Ship();

            void setupCore(WarpSystem::Core *core);

            void checkCore();

            void promote(Captain *captain);

            bool move(int warp, Destination d);

            bool move(int warp);

            bool move(Destination d);

            bool move();

            int getShield();

            void setShield(int shield);

            int getTorpedo();

            void setTorpedo(int torpedo);

            void fire(Borg::Ship *target);

            void fire(int torpedoes, Borg::Ship *target);

            private:
            int _length;
            int _width;
            int _shield;
            int _photonTorpedo;
            short _maxWarp;
            std::string _name;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
        };

        class Ensign {
            public:
            Ensign(std::string name);

            ~Ensign();

            private:
            std::string _name;
        };
    }

    class Ship {
        public:
        Ship(int _length, int _width, std::string _name);

        ~Ship();

        void setupCore(WarpSystem::Core *core);

        void checkCore();

        bool move(int warp, Destination d);

        bool move(int warp);

        bool move(Destination d);

        bool move();

        WarpSystem::Core *getCore();

        private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };
}
#endif //CPP_D07M_2018_FEDERATION_HPP
