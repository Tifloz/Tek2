/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** FailScreenEventReceiver.cpp
*/

#include "FailScreenEventReceiver.hpp"
#include "FailScreen.hpp"

FailScreenEventReceiver::FailScreenEventReceiver(irr::IrrlichtDevice *device, std::string &activTab, AudioManager *audioManager) :
_device(device), _manager(_device->getSceneManager()), _activTab(activTab), _audio(audioManager)
{
}

bool FailScreenEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        int id = event.GUIEvent.Caller->getID();
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            switch (id) {
                case FailScreen::ButtonId::TO_MENU:
                    std::cout << "clicking on to menu" << std::endl;
                    _goingToMenu = true;
                    break;
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
    return false;
}

bool FailScreenEventReceiver::isGoingToMenu() const {
    return _goingToMenu;
}

void FailScreenEventReceiver::setGoingToMenu(bool goingToMenu) {
    _goingToMenu = goingToMenu;
}
