/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** FailScreenEventReceiver.hpp
*/


#ifndef INDIE_STUDIO_WINSCREENEVENTRECEIVER_HPP
#define INDIE_STUDIO_WINSCREENEVENTRECEIVER_HPP

#include <string>
#include <irrlicht/irrlicht.h>
#include "../core/AudioManager.hpp"

class WinScreenEventReceiver : public irr::IEventReceiver {
public:
    WinScreenEventReceiver(irr::IrrlichtDevice *, std::string &, AudioManager *AudioManager);
    bool OnEvent(const irr::SEvent &event) override;
    bool isGoingToMenu() const;
    void setGoingToMenu(bool goingToMenu);

    struct SMouseState {
        irr::core::position2di position;
        bool leftButtonDown = false;
    } MouseState;

private:
    irr::IrrlichtDevice *_device;
    irr::scene::ISceneManager *_manager;
    std::string &_activTab;
    AudioManager *_audio;
    bool _goingToMenu = false;
};

#endif //INDIE_STUDIO_WINSCREENEVENTRECEIVER_HPP
