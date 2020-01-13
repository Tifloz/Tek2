/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** FailScreen.cpp
*/

#include "FailScreen.hpp"
#include "FailScreenEventReceiver.hpp"
#include <iostream>

FailScreen::FailScreen(irr::IrrlichtDevice *device, std::string &activTab, AudioManager *AudioManager) :
Tab(device, activTab, AudioManager), _audio(AudioManager), _event(FailScreenEventReceiver(device, activTab, AudioManager))
{
}

FailScreen::~FailScreen() {

}

bool FailScreen::init()
{
    _device->setEventReceiver(&_event);
    _textures["overlay"] = _driver->getTexture(
        "media/fail_screen_background.png");
    _textures["label"] = _driver->getTexture("media/gui/fail_screen_label.png");
    _transition = AnimatedTexture(_device,
        _driver->getTexture("media/menu_transition_fire2.png"), 5, 7);
    _transition.setPosition(0, 0);
    _transition.addAnimation(16, 30, 20, false, false);
    _transition.setAnimation(0);
    _transition.setScale(1.35, 1.35);

    _sadBomberman = AnimatedTexture(_device,
        _driver->getTexture("media/sad_bomberman.png"), 5, 2);
    _sadBomberman.setPosition(1920 - 834, 1080 - 692);
    _sadBomberman.addAnimation(0, 9, 100, true, false);
    _sadBomberman.setAnimation(0);

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

void FailScreen::initButtons(std::initializer_list<struct ButtonProperties> buttons)
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

void FailScreen::update()
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

void FailScreen::drawButtonsHover()
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

void FailScreen::draw()
{
    _sadBomberman.play();
    _driver->draw2DImage(_textures["overlay"],
            {0, 0},
                         irr::core::rect<irr::s32>(0, 0,
                                                   _textures["overlay"]->getSize().Width,
                                                   _textures["overlay"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _driver->draw2DImage(_textures["label"],
                         {100, 100},
                         irr::core::rect<irr::s32>(0, 0,
                                                   _textures["label"]->getSize().Width,
                                                   _textures["label"]->getSize().Height), 0,
                         irr::video::SColor(255, 255, 255, 255), true);
    _gui->drawAll();
    drawButtonsHover();
    _transition.play();
}

void FailScreen::unload()
{
    _buttons.clear();
    _gui->clear();
    _textures.clear();
    _hasFaded = false;
    _event.setGoingToMenu(false);
    _loaded = false;
}