/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** SplashEventReceiver.hpp
*/

#ifndef INDIE_STUDIO_SPLASHEVENTRECEIVER_HPP
#define INDIE_STUDIO_SPLASHEVENTRECEIVER_HPP

#include <irrlicht/IEventReceiver.h>
#include <iostream>
#include <string>
#include <irrlicht/irrlicht.h>

class SplashEventReceiver : public irr::IEventReceiver {
public:
    SplashEventReceiver(irr::IrrlichtDevice *, std::string &);
    bool OnEvent(const irr::SEvent &event) override;
    bool skip = false;
private:
    irr::IrrlichtDevice *_device;
    std::string &_activTab;

};

#endif //INDIE_STUDIO_SPLASHEVENTRECEIVER_HPP
