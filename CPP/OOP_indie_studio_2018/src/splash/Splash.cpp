/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** Splash.cpp
*/

#include <string>
#include "Splash.hpp"

Splash::Splash(irr::IrrlichtDevice *device, std::string &activTab,
    AudioManager *AudioManager
) : Tab(device, activTab, AudioManager),
    _event(SplashEventReceiver(device, activTab))
{
    _hasGui = true;
}

bool Splash::init() {
    _device->setEventReceiver(&_event);
    _background = _driver->createImage(irr::video::ECF_A1R5G5B5, {1920, 1080});
    _background->fill(irr::video::SColor(0, 0, 0, 1));
    _textures["background"] = _driver->addTexture("splashBlack", _background);
    _textures["credits"] = _driver->getTexture("media/credits.png");
    _overlay = _gui->addInOutFader();
    _overlay->setColor(irr::video::SColor(0, 0, 0, 0));
    _overlay->fadeIn(1500);
    irr::video::ITexture *splash = _driver->getTexture("media/splash.png");
    _splash = AnimatedTexture(_device, splash, 9, 11);
    _splash.setPosition(1920 / 2 - splash->getSize().Width / 9 / 2, -100);
    _splash.addAnimation(0, 93, 40, false, false);
    _splash.setAnimation(0);
    _startTime = _device->getTimer()->getTime();

    std::vector<boost::filesystem::path> splashPaths = {"media/splash/I.png",
        "media/splash/n.png", "media/splash/d.png", "media/splash/i1.png",
        "media/splash/e.png", "media/splash/-.png", "media/splash/S.png",
        "media/splash/t.png", "media/splash/u.png", "media/splash/d2.png",
        "media/splash/i2.png", "media/splash/o.png",
    };

    irr::s32 offset = 650;
    irr::s32 height = 1080;
    for (const auto &path: splashPaths) {
        _splashLetter[path.stem().c_str()].texture = _driver->getTexture(path.c_str());
        _splashLetter[path.stem().c_str()].position = irr::core::position2d<irr::s32>(offset, height);
        _splashLetter[path.stem().c_str()].rect =
                irr::core::rect<irr::s32>(0,0, _driver->getTexture(path.c_str())->getSize().Width, _driver->getTexture(path.c_str())->getSize().Height);
        offset += _driver->getTexture(path.c_str())->getSize().Width;
        height += 200;
    }

    _loaded = true;

    return true;
}

void Splash::update() {
    if ((_splash.getCurrentFrame() >= 93 || _event.skip) && !_hasFaded) {
        _overlay->fadeOut((_event.skip ? 500 : 1500));
        _hasFaded = true;
    }
    if (_hasFaded && _overlay->isReady())
        _activTab = "menu";

    if (_splash.getCurrentFrame() > 10)
        for (auto &letter: _splashLetter) {
            letter.second.position.Y -= 30;
            if (letter.second.position.Y < 800)
                letter.second.position.Y = 800;
        }
}

void Splash::draw() {
    _driver->draw2DImage(_textures["background"], {0, 0});
    _newTime = _device->getTimer()->getTime();
    if (_newTime - _startTime > 1500)
        _splash.play();
    else
        _splash.draw(0);
    _driver->draw2DImage(_textures["credits"], {20, 20},
                         irr::core::rect<irr::s32>(0,0, _textures["credits"]->getSize().Width, _textures["credits"]->getSize().Height), 0,
                         irr::video::SColor(200, 255, 255, 255), true);
    for (const auto &letter: _splashLetter)
        _driver->draw2DImage(letter.second.texture, letter.second.position,
                             letter.second.rect, 0,
                             irr::video::SColor(255, 255, 255, 255), true);
    _gui->drawAll();
}


