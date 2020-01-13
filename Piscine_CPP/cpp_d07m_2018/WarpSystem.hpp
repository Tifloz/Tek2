/*
** EPITECH PROJECT, 2022
** cpp_d07m_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef CPP_D07M_2018_WARPSYSTEM_HPP
#define CPP_D07M_2018_WARPSYSTEM_HPP
namespace WarpSystem {
    class QuantumReactor {
        public:
        QuantumReactor();

        ~QuantumReactor();

        bool isStable();

        void setStability(bool value);

        private:
        bool _stability;
    };

    class Core {
        public:
        Core(QuantumReactor *coreReactor);

        ~Core();

        QuantumReactor *checkReactor();

        private:
        QuantumReactor *_coreReactor;
    };
};
#endif //CPP_D07M_2018_WARPSYSTEM_HPP
