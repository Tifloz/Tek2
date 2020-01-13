//
// Created by gauthierbetaucourt on 5/15/19.
//

#include <iostream>
#include "Game.hpp"
#include "../menu/Menu.hpp"
#include "../board/Board.hpp"
#include "../splash/Splash.hpp"
#include "../loadingScreen/LoadingScreen.hpp"
#include "../failScreen/FailScreen.hpp"
#include "../winScreen/WinScreen.hpp"

Game::Game()
{
    _device = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(1920, 1080), 32, true, true, false,
        nullptr);
    _VDriver = _device->getVideoDriver();
    _SManager = _device->getSceneManager();
    _gui = _device->getGUIEnvironment();
    _device->setWindowCaption(irr::core::stringw("Indie-studio").c_str());

    _audioManager = new AudioManager;
    _activTab = "loading";
    _tabs["loading"] = new LoadingScreen(_device, _activTab, _audioManager);
    _tabs["splash"] = new Splash(_device, _activTab, _audioManager);
    _tabs["menu"] = new Menu(_device, _activTab, _audioManager, &multiplayer);
    _tabs["board"] = new Board(_device, _activTab, _audioManager, &multiplayer);
    _tabs["win"] = new WinScreen(_device, _activTab, _audioManager);
    _tabs["fail"] = new FailScreen(_device, _activTab, _audioManager);
    _tabs[_activTab]->init();
}

Game::~Game()
{
    for (auto tab : _tabs)
        delete tab.second;
    _device->drop();
    delete _audioManager;
}

int Game::run()
{
    while (_device->run()) {
        if (!_tabs[_activTab]->isLoaded()) {
            for (auto tab : _tabs)
                tab.second->unload();
            _SManager->clear();
            _gui->clear();
            if (!_tabs[_activTab]->init())
                _device->closeDevice();
        }
        _tabs[_activTab]->update();
        if (!_tabs[_activTab]->isLoaded()) {
            for (auto tab : _tabs)
                tab.second->unload();
            _SManager->clear();
            _gui->clear();
            if (!_tabs[_activTab]->init())
                _device->closeDevice();
        }
        _VDriver->beginScene(true, true,
            irr::video::SColor(255, 255, 255, 255));
        _SManager->drawAll();
        _tabs[_activTab]->draw();
        _VDriver->endScene();
    }
    return 0;
}