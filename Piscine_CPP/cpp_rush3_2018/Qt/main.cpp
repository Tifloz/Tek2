/*
** EPITECH PROJECT, 2022
** MyTest
** File description:
** Created by Florian Louvet,
*/
#include <QtWidgets>
#include <QApplication>
#include <QGridLayout>
#include <iostream>
#include "cpuModule.hpp"
#include "RAM.hpp"
#include "window.hpp"
#include "CPU.hpp"

int startTextMode();

int startGraphic(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    QWidget group;
    auto *layout = new QGridLayout;
    auto *core_all = new cpuModule();
    auto *ram_all = new ramModule();
    CPUGraph *cpu = new CPUGraph("CPU 0", 100, core_all->getInfo().getCore());
    CPUGraph *cpu1 = new CPUGraph("CPU 1", 100, core_all->getInfo().getCore());
    CPUGraph *cpu2 = new CPUGraph("CPU 2", 100, core_all->getInfo().getCore());
    CPUGraph *cpu3 = new CPUGraph("CPU 3", 100, core_all->getInfo().getCore());
    RAMGraph *ram = new RAMGraph("RAM", 8, ram_all);
    QLabel *kernel = new QLabel("Kernel : " + QSysInfo::kernelVersion());
    QLabel *hostname = new QLabel("hostname : " + QSysInfo::machineHostName());
    ram_all->update();
    QLabel *ram_sum = new QLabel(
        "RAM (GB) : " + QString::fromStdString(ram_all->getUsed()) + "/" +
            QString::fromStdString(ram_all->getTotal()));
    QChartView cpu_v(cpu);
    QChartView cpu_v1(cpu1);
    QChartView cpu_v2(cpu2);
    QChartView cpu_v3(cpu3);
    QChartView ram_v(ram);

    cpu_v.setRenderHint(QPainter::Antialiasing);
    cpu_v1.setRenderHint(QPainter::Antialiasing);
    cpu_v2.setRenderHint(QPainter::Antialiasing);
    cpu_v3.setRenderHint(QPainter::Antialiasing);
    ram_v.setRenderHint(QPainter::Antialiasing);

    layout->setAlignment(Qt::AlignCenter);
    auto *cpu_status = new QCheckBox("CPU 0");
    cpu_status->setChecked(true);
    auto *cpu1_status = new QCheckBox("CPU 1");
    cpu1_status->setChecked(true);
    auto *cpu2_status = new QCheckBox("CPU 2");
    cpu2_status->setChecked(true);
    auto *cpu3_status = new QCheckBox("CPU 3");
    cpu3_status->setChecked(true);
    auto *ram_status = new QCheckBox("RAM");
    ram_status->setChecked(true);

    layout->setHorizontalSpacing(0);
    layout->addWidget(&cpu_v, 0, 0);
    layout->addWidget(cpu_status, 1, 0);
    layout->addWidget(&cpu_v1, 0, 1);
    layout->addWidget(cpu1_status, 1, 1);
    layout->addWidget(&cpu_v2, 0, 2);
    layout->addWidget(cpu2_status, 1, 2);
    layout->addWidget(&cpu_v3, 0, 3);
    layout->addWidget(cpu3_status, 1, 3);
    layout->addWidget(&ram_v);
    layout->addWidget(ram_status, 3, 0);
    layout->addWidget(kernel);
    layout->addWidget(hostname);
    layout->addWidget(ram_sum);

    QObject::connect(cpu_status, SIGNAL(clicked(bool)), cpu,
        SLOT(displayChart(bool)));
    QObject::connect(cpu1_status, SIGNAL(clicked(bool)), cpu1,
        SLOT(displayChart(bool)));
    QObject::connect(cpu2_status, SIGNAL(clicked(bool)), cpu2,
        SLOT(displayChart(bool)));
    QObject::connect(cpu3_status, SIGNAL(clicked(bool)), cpu3,
        SLOT(displayChart(bool)));
    QObject::connect(ram_status, SIGNAL(clicked(bool)), ram,
        SLOT(displayChart(bool)));
    group.setLayout(layout);
    window.setCentralWidget(&group);
    window.setMinimumSize(900, 900);
    window.show();
    return QApplication::exec();
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage : ./MyGKrellm [text|graphic]" << std::endl;
        return 0;
    } else if (std::string("text") == av[1])
        return startTextMode();
    else if (std::string("graphic") == av[1])
        return startGraphic(ac, av);
    else if (std::string("-h") == av[1]) {
        std::cout << "Usage : ./MyGKrellm [text|graphic]" << std::endl;
        return 0;
    }
    std::cout << "Usage : ./MyGKrellm [text|graphic]" << std::endl;
    return 1;
}