/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** SplashEventReceiver.cpp
*/

#include "SplashEventReceiver.hpp"

SplashEventReceiver::SplashEventReceiver(irr::IrrlichtDevice *device, std::string &activTab) :
_device(device), _activTab(activTab)
{
}

bool SplashEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
        if (event.MouseInput.isLeftPressed())
            skip = true;
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        switch (event.KeyInput.Key) {
            case irr::KEY_SPACE:
                skip = true;
                break;
            case irr::KEY_ESCAPE:
                skip = true;
                break;
            case irr::KEY_RETURN:
                skip = true;
                break;
            default:
                return true;
        }
    }
    return false;
}

