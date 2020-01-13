//
// Created by gauthierbetaucourt on 5/15/19.
//

#ifndef OOP_INDIE_STUDIO_2018_GAME_HPP
#define OOP_INDIE_STUDIO_2018_GAME_HPP

#include <vector>
#include <irrlicht/irrlicht.h>
#include "../core/AudioManager.hpp"
#include "../input.hpp"
#include "../core/Tab.hpp"
#include "../menu/Menu.hpp"

class Game {
    public:
    Game();
    ~Game();

    int run();
    bool multiplayer = false;

    private:
    irr::IrrlichtDevice *_device;
    irr::video::IVideoDriver *_VDriver;
    irr::scene::ISceneManager *_SManager;
    irr::gui::IGUIEnvironment *_gui;
    std::map<std::string, Tab *> _tabs;
    std::string _activTab;
    AudioManager *_audioManager;
    public:
    void setNextActiveTab(const std::string &nextActiveTab);
};

#endif //OOP_INDIE_STUDIO_2018_GAME_HPP
