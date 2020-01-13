/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "CPU.hpp"

CPUGraph::CPUGraph(const QString title, qreal maxValue, usageCPU core, cpuModule cpu) :
Chart(title, maxValue, core)
{
    axisY()->setRange(0, 100);
}

CPUGraph::~CPUGraph() = default;

