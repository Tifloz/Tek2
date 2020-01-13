/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** Splash.hpp
*/

#ifndef INDIE_STUDIO_SPLASH_HPP
#define INDIE_STUDIO_SPLASH_HPP

#include <irrlicht/irrlicht.h>
#include "../core/Tab.hpp"
#include "../animatedTexture/AnimatedTexture.hpp"
#include "SplashEventReceiver.hpp"
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>


class Splash : public Tab
{
public:
    Splash(irr::IrrlichtDevice *, std::string &, AudioManager *);

    bool init() override;
    void update() override;
    void draw() override;

private:
    SplashEventReceiver _event;
    irr::video::IImage *_background;
    std::map<std::string, irr::video::ITexture *> _textures;
    irr::u32 _startTime;
    irr::u32 _newTime;
    irr::gui::IGUIInOutFader *_overlay;
    bool _hasFaded = false;
    AnimatedTexture _splash;
    struct splashLetter {
        irr::video::ITexture *texture;
        irr::core::position2d<irr::s32> position;
        irr::core::rect<irr::s32> rect;
    };
    std::map<std::string, splashLetter> _splashLetter;
};

#endif //INDIE_STUDIO_SPLASH_HPP
