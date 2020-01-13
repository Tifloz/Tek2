/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLM_RAM_HPP
#define MYGKRELLM_RAM_HPP

#include "Chart.hpp"

class RAMGraph : public Chart {
    public:
    RAMGraph(QString title, qreal maxValue = 8, ramModule ram = ramModule());

    ~RAMGraph() override;
};

#endif //MYGKRELLM_RAM_HPP
