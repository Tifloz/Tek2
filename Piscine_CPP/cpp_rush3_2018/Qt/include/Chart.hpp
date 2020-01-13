/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLM_CHART_HPP
#define MYGKRELLM_CHART_HPP

#include <QtCharts/QChart>
#include <QtCharts/QtCharts>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTimer>
#include "cpuModule.hpp"
#include "ramModule.hpp"

class Chart : public QtCharts::QChart {
    Q_OBJECT
    public:
    Chart(QString title = "", qreal maxValue = 100, usageCPU core = usageCPU(),
        cpuModule cpu = cpuModule());

    Chart(QString title = "", qreal maxValue = 100,
        ramModule ram = ramModule());

    ~Chart() override;

    public slots:

    void displayChart(bool status);

    void updateCPU();

    void updateRAM();

    protected:
    QTimer _timer;
    QSplineSeries *_series;
    QStringList _titles;
    QValueAxis *_axis;
    qreal _step;
    qreal _x;
    qreal _y;
    qreal _maxValue;
    ramModule ram;
    usageCPU core;
    cpuModule cpu;
};

#endif //MYGKRELLM_CHART_HPP
