/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#include "RAM.hpp"

RAMGraph::RAMGraph(const QString title, const qreal maxValue, ramModule ram) : Chart(title,
    maxValue, ram)
{
    axisY()->setRange(0, 8);
}

RAMGraph::~RAMGraph() = default;

