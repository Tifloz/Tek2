/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef TAB_H
#define TAB_H

#include <irrlicht/irrlicht.h>
#include <map>
#include "Image.hpp"
#include "AudioManager.hpp"

class Tab {
    public:
    Tab(irr::IrrlichtDevice *, std::string &, AudioManager *audioManager);

    virtual ~Tab();

    virtual bool init() = 0;

    virtual void update() = 0;

    virtual void draw() = 0;

    bool isLoaded() const;

    virtual void unload();

    protected:
    AudioManager *_AudioManager;
    irr::IrrlichtDevice *_device;
    irr::video::IVideoDriver *_driver;
    irr::scene::ISceneManager *_manager{};
    irr::gui::IGUIEnvironment *_gui;
    std::string &_activTab;
    std::map<std::string, Image *> _images;
    std::map<std::string, irr::scene::IMeshSceneNode *> _scenes;
    bool _loaded = false;
    bool _hasGui = true;
    public:
    bool hasGui() const;
};

#endif