/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** Created by Jonathan Lefebvre,
*/

#ifndef CPP_RUSH3_2018_INFOCPU_HPP
#define CPP_RUSH3_2018_INFOCPU_HPP

#include <list>
#include "../IMonitorModule.hpp"
#include "baseModule.hpp"

class usageCPU {
    public:
        usageCPU();

    public:
        int _user;
        int _nice;
        int _system;
        int _idle;
        int _iowait;
        int _irq;
        int _softiro;
        int _steal;
        std::string _totalUsage;
        std::string _frequency;
};

class infoCPU {
    public:
    infoCPU();

    std::string _vendor;
    std::string _modelName;
    std::string _nbrCore;
    std::list<usageCPU> _usageCore;

    usageCPU getCore() const;

    usageCPU _usage;
};

class cpuModule : public baseModule {
    public:
    explicit cpuModule(bool isEnable = true);

    virtual ~cpuModule();

    bool update() override;

    const infoCPU &getInfo() const;

    protected:
    infoCPU _info;
};

#endif //CPP_RUSH3_2018_INFOCPU_HPP
