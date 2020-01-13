/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** LoadingScreen.cpp
*/

#include "LoadingScreen.hpp"

LoadingScreen::LoadingScreen(irr::IrrlichtDevice *device, std::string &activTab,
    AudioManager *AudioManager
) : Tab(device, activTab, AudioManager)
{
}

bool LoadingScreen::init()
{
    irr::video::IImage *blackOverlay = _driver->createImage(
        irr::video::ECF_A1R5G5B5, {1920, 1080});
    blackOverlay->fill(irr::video::SColor(0, 0, 0, 1));
    _textures["background"] = _driver->getTexture(
        "media/loading_background.jpg");
    _spinner = AnimatedTexture(_device,
        _driver->getTexture("media/loading_spinner.png"), 5, 6);
    _spinner.addAnimation(0, 29, 15, true, false);
    _spinner.setAnimation(0);
    _spinner.setPosition(20, 120);

    _textures["loading"] = _driver->getTexture("media/loading.png");
    _textures["loadingBarBackground"] = _driver->getTexture(
        "media/gui/bar_background.png");
    _textures["loadingBarForeground"] = _driver->getTexture(
        "media/gui/bar_foreground.png");

    for (const auto &it : recursive_directory_range("media/")) {
        const boost::filesystem::path &path = it;
        _paths.push_back(path);
        _totalCount++;
    }

    _loaded = true;
    return true;
}

void LoadingScreen::update()
{
    if (_count < _totalCount) {
        _driver->getTexture(_paths[_count].c_str());
        _count++;
    }
    if (_count == _totalCount)
        _activTab = "splash";
}

void LoadingScreen::draw()
{
    _driver->draw2DImage(_textures["background"], {0, 0});
    _driver->draw2DImage(_textures["loadingBarBackground"],
        {static_cast<int>(1920 / 2 -
            (_textures["loadingBarBackground"]->getSize().Width / 2)), 700},
                         irr::core::rect<irr::s32>(0, 0, _textures["loadingBarBackground"]->getSize().Width,
                                                   _textures["loadingBarBackground"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _driver->draw2DImage(_textures["loading"], {20, 20},
        irr::core::rect<irr::s32>(0, 0, _textures["loading"]->getSize().Width,
            _textures["loading"]->getSize().Height), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    _driver->draw2DImage(_textures["loadingBarForeground"],
        {static_cast<int>(1920 / 2 -
            (_textures["loadingBarBackground"]->getSize().Width / 2)), 700},
        irr::core::rect<irr::s32>(0, 0,
            _textures["loadingBarForeground"]->getSize().Width *
                (static_cast<float>(_count) / static_cast<float>(_totalCount)),
            _textures["loadingBarForeground"]->getSize().Height), 0,
        irr::video::SColor(255, 255, 255, 255), true);
    _spinner.play();
}
