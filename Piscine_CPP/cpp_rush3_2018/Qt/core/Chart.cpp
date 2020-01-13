/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#include "Chart.hpp"
#include "cpuModule.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Chart::~Chart() = default;

Chart::Chart(QString title, qreal maxValue, ramModule ram) : QChart(
    QChart::ChartTypeCartesian, nullptr, nullptr), _series(nullptr),
    _axis(new QValueAxis), _step(0), _x(5), _y(1)
{
    QObject::connect(&_timer, &QTimer::timeout, this, (&Chart::updateRAM));
    _timer.setInterval(1000);

    _series = new QSplineSeries(this);

    _series->append(_x, _y);

    addSeries(_series);
    createDefaultAxes();
    setAxisX(_axis, _series);
    _axis->setTickCount(5);

    this->legend()->hide();
    this->setTitle(title);
    this->axisX()->hide();
    this->setAnimationOptions(QChart::SeriesAnimations);
    this->setTheme(QChart::ChartThemeDark);

    _timer.start();
}

Chart::Chart(QString title, qreal maxValue, usageCPU core, cpuModule cpu)
    : QChart(QChart::ChartTypeCartesian, nullptr, nullptr), _series(nullptr),
    _axis(new QValueAxis), _step(0), _x(5), _y(1)
{
    QObject::connect(&_timer, &QTimer::timeout, this, (&Chart::updateCPU));
    _timer.setInterval(1000);

    _series = new QSplineSeries(this);

    _series->append(_x, _y);

    addSeries(_series);
    createDefaultAxes();
    setAxisX(_axis, _series);
    _axis->setTickCount(5);

    this->legend()->hide();
    this->setTitle(title);
    this->axisX()->hide();
    this->setAnimationOptions(QChart::SeriesAnimations);
    this->setTheme(QChart::ChartThemeDark);

    _timer.start();
}

void Chart::updateCPU()
{
    cpu.update();
    qreal x = plotArea().width() / _axis->tickCount();
    qreal y = (_axis->max() - _axis->min()) / _axis->tickCount();
    _x += y;
    _y = atof(cpu.getInfo().getCore()._totalUsage.c_str());

    _series->append(_x, _y);
    if (_y >= 50 && _y < 75)
        _series->setColor(Qt::yellow);
    else if (_y < 50)
        _series->setColor(Qt::green);
    else if (_y >= 75)
        _series->setColor(Qt::red);
    scroll(x, 0);
    if (_x == 100)
        _timer.stop();
}

void Chart::displayChart(bool status)
{
    if (status)
        this->show();
    else
        this->hide();
}

void Chart::updateRAM()
{
    this->ram.update();
    qreal x = plotArea().width() / _axis->tickCount();
    qreal y = (_axis->max() - _axis->min()) / _axis->tickCount();
    _x += y;
    _y = atof(this->ram.getUsed().c_str());

    _series->append(_x, _y);
    if (_y >= 5 && _y < 7)
        _series->setColor(Qt::yellow);
    else if (_y < 5)
        _series->setColor(Qt::green);
    else if (_y >= 7)
        _series->setColor(Qt::red);
    scroll(x, 0);
    if (_x == 100)
        _timer.stop();
}

