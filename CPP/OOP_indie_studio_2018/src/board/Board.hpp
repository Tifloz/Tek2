/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <irrlicht/irrlicht.h>
#include "../animatedTexture/AnimatedTexture.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Bomb.hpp"
#include "../core/Tab.hpp"
#include "BoardEventReceiver.hpp"
#include "Cube.hpp"
#include "Powerup.hpp"

class Board : public Tab
{
public:
    Board(irr::IrrlichtDevice *, std::string &, AudioManager *, bool *);
    ~Board();

    bool init() override;
    void update() override;
    void draw() override;
    void unload() override;
    void createPlayers();
    void addWall(int, int);
    void initMap();

    enum ButtonId {
        BEGIN,
        RESUME,
        SAVE,
        QUIT_TO_MENU,
        QUIT_TO_DESKTOP,
        QUIT_CONFIRM,
        QUIT_CANCEL,
        COUNT,
    };
private:
    void drawButtonsHover();
    void checkIfCameraMustShake();
    void deleteBombIfItHasExploded(int position);

    void killPlayerIfItsDead(
        std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, Beam>> it
    );
    void checkIfAllPlayersAreDead();
    void checkPowerupSpawn();
    struct ButtonProperties {
        std::string mapKey;
        irr::core::position2df pos;
        irr::gui::IGUIElement *parent;
        std::string texturePath;
        std::string pressedTexturePath;
        std::string hoverTexturePath;
        int id;
    };
    struct Button {
        irr::gui::IGUIButton *button;
        irr::core::rect<irr::s32> rectangle;
        irr::video::ITexture *hoverTexture;
        unsigned short hoverAlpha;
        unsigned int hoverWidth;
    };
    void initButtons(std::initializer_list<struct ButtonProperties> buttons);
    std::map<std::string, struct Button> _buttons;
    Map _map;
    AudioManager *_audio;
    AnimatedTexture _transition;
    irr::scene::IMetaTriangleSelector *_meta;
    std::vector<Player *> _players;
    std::vector<Bomb *> _bombs;
    BoardEventReceiver _event;
    std::vector<Cube *> _ground;
    std::map<std::string, irr::video::ITexture *> _textures;
    bool *_multiplayer;
    irr::ITimer *_timer;
    irr::u32 _lastPowerup;
    bool _playEndingTransition = false;
    bool _isWon = false;
    AnimatedTexture _endingTransition;
    std::vector<Powerup *> _powerups;
};

#endif