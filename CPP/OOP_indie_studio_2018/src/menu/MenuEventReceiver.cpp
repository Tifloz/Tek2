/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include <iostream>
#include "../core/AudioManager.hpp"
#include "MenuEventReceiver.hpp"
#include "../map/Generator.hpp"

MenuEventReceiver::MenuEventReceiver(irr::IrrlichtDevice *device,
    std::string &activTab, AudioManager *AudioManager, bool *multiplayer
) : _device(device), _gui(_device->getGUIEnvironment()), _activTab(activTab),
    _AudioManager(AudioManager), _multiplayer(multiplayer)
{
}

bool MenuEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        if (event.KeyInput.Key == irr::KEY_ESCAPE && event.KeyInput.PressedDown && _state == "options" && !_scrolling) {
            _state = "menu";
        }
    }

    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
        case irr::gui::EGET_BUTTON_CLICKED:
            _AudioManager->Play(Click);
            switch (id) {
            case Buttons::SINGLEPLAYER:
                _launchChoice = (_launchChoice.empty() || _launchChoice == "2p" ? "1p" : "");
                return true;
            case Buttons::MULTIPLAYER:
                _launchChoice = (_launchChoice.empty() || _launchChoice == "1p" ? "2p" : "");
                return true;
            case Buttons::OPTIONS:
                if (!_scrolling)
                    _state = "options";
                return true;
            case Buttons::QUIT:
                _state = (_state == "quit" ? "menu" : "quit");
                return true;
            case Buttons::BACK_TO_MENU:
                if (!_scrolling)
                    _state = "menu";
                return true;
            case Buttons::QUIT_CANCEL:
                _state = "menu";
                return true;
            case Buttons::QUIT_CONFIRM:
                _device->closeDevice();
                return true;
            case Buttons::NEW_GAME:
                {
                    _playTransition = true;
                    *_multiplayer = (_launchChoice == "2p");
                    Generator tue("Map.txt");
                    return true;
                }
            case Buttons::LOAD_GAME:
                _playTransition = true;
                *_multiplayer = (_launchChoice == "2p");
                return true;
            default:
                break;
            }
        default:
            break;
        }
    }

    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
        switch (event.MouseInput.Event) {
            case irr::EMIE_MOUSE_MOVED:
                MouseState.position.X = event.MouseInput.X;
                MouseState.position.Y = event.MouseInput.Y;
                break;
            case irr::EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.leftButtonDown = true;
                break;
            case irr::EMIE_LMOUSE_LEFT_UP:
                MouseState.leftButtonDown = false;
                break;
            default:
                break;
        }
    }
    return false;}

unsigned int MenuEventReceiver::getGameVolume() const
{
    return _volume;
}


unsigned int MenuEventReceiver::getGameEffectsVolume() const
{
    return _effectsVolume;
}

void MenuEventReceiver::setVolume(unsigned int volume)
{
    _volume = volume;
}

void MenuEventReceiver::setEffectVolume(unsigned int effectVolume)
{
    _effectsVolume = effectVolume;
}

std::string MenuEventReceiver::getState() const
{
    return _state;
}

unsigned int MenuEventReceiver::getMusicVolume() const {
    return _musicVolume;
}

void MenuEventReceiver::setMusicVolume(unsigned int volume) {
    _musicVolume = volume;
}

void MenuEventReceiver::setState(const std::string &state) {
    _state = state;
}

bool MenuEventReceiver::isScrolling() const {
    return _scrolling;
}

void MenuEventReceiver::setScrolling(bool scrolling) {
    _scrolling = scrolling;
}

const std::string &MenuEventReceiver::getLaunchChoice() const {
    return _launchChoice;
}

void MenuEventReceiver::setLaunchChoice(const std::string &launchChoice) {
    _launchChoice = launchChoice;
}
