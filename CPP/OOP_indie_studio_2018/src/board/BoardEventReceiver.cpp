/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "BoardEventReceiver.hpp"
#include "Board.hpp"
#include "../save/Save.hpp"

BoardEventReceiver::BoardEventReceiver(irr::IrrlichtDevice *device, std::string &activTab, Map &map, std::vector<Player *> &players) :
_device(device), _manager(_device->getSceneManager()), _activTab(activTab), _player1(nullptr), _player2(nullptr), _map(map), _players(players)
{
}

void BoardEventReceiver::setP1(Player *p1)
{
    _player1 = p1;
}

void BoardEventReceiver::setP2(Player *p2)
{
    _player2 = p2;
}

bool BoardEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        int id = event.GUIEvent.Caller->getID();
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            switch (id) {
                case Board::ButtonId::RESUME:
                    _pause = false;
                    _quittingChoice = "";
                    break;
                case Board::ButtonId::SAVE:
                {Save toto("Map.txt", _map, _players);}
                    // Button save
                    break;
                case Board::ButtonId::QUIT_TO_MENU:
                    _quittingChoice = _quittingChoice == "menu" ? "" : "menu";
                    break;
                case Board::ButtonId::QUIT_TO_DESKTOP:
                    _quittingChoice = _quittingChoice == "desktop" ? "" : "desktop";
                    break;
                case Board::ButtonId::QUIT_CONFIRM:
                    _pause = false;
                    if (_quittingChoice == "menu") {
                        _quittingChoice = "";
                        _activTab = "menu";
                    } else if (_quittingChoice == "desktop") {
                        _device->closeDevice();
                    }
                    break;
                case Board::ButtonId::QUIT_CANCEL:
                    _quittingChoice = "";
                    break;
                default:
                    break;
            }
    }

    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        switch (event.KeyInput.Key) {
        case irr::KEY_KEY_Z:
            _player1->setAction("up", event.KeyInput.PressedDown);
            break;
        case irr::KEY_KEY_Q:
            _player1->setAction("left", event.KeyInput.PressedDown);
            break;
        case irr::KEY_KEY_S:
            _player1->setAction("down", event.KeyInput.PressedDown);
            break;
        case irr::KEY_KEY_D:
            _player1->setAction("right", event.KeyInput.PressedDown);
            break;
        case irr::KEY_SPACE:
            _player1->setAction("bomb", event.KeyInput.PressedDown);
            break;
        case irr::KEY_ESCAPE:
                if (event.KeyInput.PressedDown) {
                    _pause = !_pause;
                    if (!_pause) {
                        _quittingChoice = "";
                    }
                }
            break;
        default:
            break;
        }
        if (_player2)
            switch (event.KeyInput.Key) {
            case irr::KEY_UP:
                _player2->setAction("up", event.KeyInput.PressedDown);
                break;
            case irr::KEY_LEFT:
                _player2->setAction("left", event.KeyInput.PressedDown);
                break;
            case irr::KEY_DOWN:
                _player2->setAction("down", event.KeyInput.PressedDown);
                break;
            case irr::KEY_RIGHT:
                _player2->setAction("right", event.KeyInput.PressedDown);
                break;
            case irr::KEY_RETURN:
                _player2->setAction("bomb", event.KeyInput.PressedDown);
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

bool BoardEventReceiver::isPause() const {
    return _pause;
}

void BoardEventReceiver::setPause(bool pause) {
    _pause = pause;
}

const std::string &BoardEventReceiver::getQuittingChoice() const {
    return _quittingChoice;
}
