/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLM_CPU_HPP
#define MYGKRELLM_CPU_HPP

#include "Chart.hpp"

class CPUGraph : public Chart {
    public:
    explicit CPUGraph(QString title = "", qreal maxValue = 100,
        usageCPU core = usageCPU(), cpuModule cpu = cpuModule());

    ~CPUGraph() override;
};

#endif //MYGKRELLM_CPU_HPP
