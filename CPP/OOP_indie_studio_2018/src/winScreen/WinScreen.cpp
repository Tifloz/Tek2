/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** WinScreen.cpp
*/


#include "WinScreen.hpp"
#include "WinScreenEventReceiver.hpp"
#include <iostream>

WinScreen::WinScreen(irr::IrrlichtDevice *device, std::string &activTab, AudioManager *AudioManager) :
        Tab(device, activTab, AudioManager), _audio(AudioManager), _event(WinScreenEventReceiver(device, activTab, AudioManager))
{
}

WinScreen::~WinScreen() {

}

bool WinScreen::init()
{
    _device->setEventReceiver(&_event);
    _transition = AnimatedTexture(_device,
        _driver->getTexture("media/menu_transition_fire2.png"), 5, 7);
    _transition.setPosition(0, 0);
    _transition.addAnimation(16, 30, 20, false, false);
    _transition.setAnimation(0);
    _transition.setScale(1.35, 1.35);

    _happyBomberman = AnimatedTexture(_device,
        _driver->getTexture("media/dancing_bomberman.png"), 5, 3);
    _happyBomberman.setPosition(0, -60);
    _happyBomberman.addAnimation(0, 14, 100, true, false);
    _happyBomberman.setAnimation(0);

    _textures["background"] = _driver->getTexture(
        "media/win_screen_background.jpg");
    _textures["happyBomberman"] = _driver->getTexture(
        "media/happy_bomberman.png");
    _textures["label"] = _driver->getTexture("media/gui/win_screen_label.png");

    initButtons({
                        {
                                .mapKey = "toMenu",
                                .pos = {100, 800},
                                .parent = 0, .texturePath = "media/gui/return_to_menu.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/return_to_menu_hover.png",
                                .id = ButtonId::TO_MENU
                        },
                });

    _overlay = _gui->addInOutFader();
    _overlay->setColor(irr::video::SColor(0, 0, 0, 0));
    _overlay->setVisible(false);

    _loaded = true;
    return true;
}

void WinScreen::initButtons(std::initializer_list<struct ButtonProperties> buttons)
{
    for (const auto &button : buttons) {
        std::string mapKey = button.mapKey;
        std::cout << "Setting up button of key: '" << mapKey << "'"
                  << std::endl;
        irr::video::ITexture *image = _driver->getTexture(
                button.texturePath.c_str());
        irr::core::rect<irr::s32> rect = {static_cast<int>(button.pos.X),
                                          static_cast<int>(button.pos.Y),
                                          static_cast<int>(button.pos.X + image->getSize().Width),
                                          static_cast<int>(button.pos.Y + image->getSize().Height)};
        _buttons[mapKey].button = _gui->addButton(rect, button.parent,
                                                  button.id);
        _buttons[mapKey].button->setImage(image);
        if (!button.pressedTexturePath.empty())
            _buttons[mapKey].button->setPressedImage(
                    _driver->getTexture(button.pressedTexturePath.c_str()));
        _buttons[mapKey].button->setDrawBorder(false);
        _buttons[mapKey].button->setUseAlphaChannel(true);
        _buttons[mapKey].rectangle = rect;
        _buttons[mapKey].hoverAlpha = 0;
        _buttons[mapKey].hoverWidth = 0;
        if (!button.hoverTexturePath.empty())
            _buttons[mapKey].hoverTexture = _driver->getTexture(
                    button.hoverTexturePath.c_str());
    }
}

void WinScreen::update()
{
    if (_event.isGoingToMenu() && !_hasFaded) {
        _overlay->fadeOut(500);
        _overlay->setVisible(true);
        _hasFaded = true;
    }
    if (_event.isGoingToMenu() && _overlay->isReady()) {
        _activTab = "menu";
    }
}

void WinScreen::drawButtonsHover()
{
    unsigned int fadeSpeed = 50;
    unsigned int uncoverSpeed = 35;
    for (auto &button: _buttons) {
        auto btn = &button.second;
        if (btn->button->getAbsolutePosition().isPointInside(
                {static_cast<int>(_event.MouseState.position.X),
                 static_cast<int>(_event.MouseState.position.Y)})) {
            btn->hoverAlpha += fadeSpeed;
            if (btn->hoverAlpha > 255)
                btn->hoverAlpha = 255;
            btn->hoverWidth += uncoverSpeed;
            if (btn->hoverTexture)
                if (btn->hoverWidth > btn->hoverTexture->getSize().Width)
                    btn->hoverWidth = btn->hoverTexture->getSize().Width;
        } else {
            btn->hoverAlpha -= fadeSpeed;
            if (btn->hoverAlpha > 255)
                btn->hoverAlpha = 0;
            btn->hoverWidth -= uncoverSpeed;
            if (btn->hoverTexture)
                if (btn->hoverWidth > btn->hoverTexture->getSize().Width)
                    btn->hoverWidth = 0;
        }
        if (btn->hoverTexture)
            _driver->draw2DImage(btn->hoverTexture,
                                 irr::core::position2d<irr::s32>(
                                         btn->button->getAbsolutePosition().UpperLeftCorner),
                                 irr::core::rect<irr::s32>(0, 0, btn->hoverTexture->getSize().Width,
                                                           btn->hoverTexture->getSize().Height), 0,
                                 irr::video::SColor(btn->hoverAlpha, 255, 255, 255), true);
    }
}

void WinScreen::draw()
{
    _driver->draw2DImage(_textures["background"],
                         {0, 0},
                         irr::core::rect<irr::s32>(0, 0,
                                                   _textures["background"]->getSize().Width,
                                                   _textures["background"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _driver->draw2DImage(_textures["label"],
                         {550, 450},
                         irr::core::rect<irr::s32>(0, 0,
                                                   _textures["label"]->getSize().Width,
                                                   _textures["label"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _driver->draw2DImage(_textures["happyBomberman"],
                         {1300, 100},
                         irr::core::rect<irr::s32>(0, 0,
                                                   _textures["happyBomberman"]->getSize().Width,
                                                   _textures["happyBomberman"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _happyBomberman.play();
    _gui->drawAll();
    drawButtonsHover();
    _transition.play();
}

void WinScreen::unload()
{
    std::cout << "Unloading WinScreen" << std::endl;
    _buttons.clear();
    _gui->clear();
    _textures.clear();
    _hasFaded = false;
    _event.setGoingToMenu(false);
    _loaded = false;
}