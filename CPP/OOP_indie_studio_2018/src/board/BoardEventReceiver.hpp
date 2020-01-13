/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef BOARDEVENTRECEIVER_H
#define BOARDEVENTRECEIVER_H

#include <string>
#include <irrlicht/irrlicht.h>
#include "Player.hpp"

class BoardEventReceiver : public irr::IEventReceiver
{
public:
    struct SMouseState {
        irr::core::position2di position;
        bool leftButtonDown = false;
    } MouseState;
    BoardEventReceiver(irr::IrrlichtDevice *, std::string &, Map &, std::vector<Player *> &);

    void setP1(Player *);
    void setP2(Player *);
    bool OnEvent(const irr::SEvent &event) override;
    void setPause(bool pause);
    bool isPause() const;
    const std::string &getQuittingChoice() const;

private:
    irr::IrrlichtDevice *_device;
    irr::scene::ISceneManager *_manager;
    std::string &_activTab;
    Player *_player1;
    Player *_player2;
    Map &_map;
    std::vector<Player *> &_players;
    bool _pause = false;
    std::string _quittingChoice = "";
};

#endif