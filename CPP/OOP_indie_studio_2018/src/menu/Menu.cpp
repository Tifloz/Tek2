//
// Created by gauthierbetaucourt on 5/16/19.
//

#include <vector>
#include <iostream>
#include <irrlicht/IVideoDriver.h>
#include <algorithm>
#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *device, std::string &activTab,
    AudioManager *AudioManager, bool *multiplayer
) : Tab(device, activTab, AudioManager),
    _event(MenuEventReceiver(device, activTab, AudioManager, multiplayer))
{
}

Menu::~Menu()
{
    for (const auto &image : _images)
        delete image.second;
}

void Menu::unload()
{
    std::cout << "Unloading Menu" << std::endl;
    _gui->clear();
    _buttons.clear();
    _images.clear();
    _event.setLaunchChoice("");
    _loaded = false;
}

bool Menu::init()
{
    _device->setEventReceiver(&_event);
    _manager = _device->getSceneManager();
    _images["background"] = new Image(_device->getVideoDriver(),
        "media/menu7-2.jpg", irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 3440, 1440),
        irr::video::SColor(255, 255, 255, 255));
    initButtons({{.mapKey = "play1p", .pos = {20,
        20}, .parent = nullptr, .texturePath = "media/gui/play1p.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/play1p_hover.png", .id = 1,},
        {.mapKey = "play2p", .pos = {20, 20 + 20 + 180 *
            1}, .parent = nullptr, .texturePath = "media/gui/play2p.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/play2p_hover.png", .id = 2,},
        {.mapKey = "options", .pos = {20, 20 + 20 + 180 * 2 +
            20}, .parent = nullptr, .texturePath = "media/gui/options.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/options_hover.png", .id = 3,},
        {.mapKey = "quit", .pos = {20, 20 + 20 + 180 * 3 +
            40}, .parent = nullptr, .texturePath = "media/gui/quit.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_hover.png", .id = 4,},
        {.mapKey = "back", .pos = {1920 + 20,
            20}, .parent = nullptr, .texturePath = "media/gui/left_arrow.png", .pressedTexturePath = "", .hoverTexturePath = "", .id = 5,},
        {.mapKey = "volSlider", .pos = {1920 + 980 + 122,
            40}, .parent = nullptr, .texturePath = "media/gui/slider_bg.png", .pressedTexturePath = "", .hoverTexturePath = "", .id = 7,},
        {.mapKey = "effectVolSlider", .pos = {1920 + 980 + 122 * 2,
            160}, .parent = nullptr, .texturePath = "media/gui/slider_bg.png", .pressedTexturePath = "", .hoverTexturePath = "", .id = 10,},
        {.mapKey = "musicVolSlider", .pos = {1920 + 980 + 122 * 2,
            280}, .parent = nullptr, .texturePath = "media/gui/slider_bg.png", .pressedTexturePath = "", .hoverTexturePath = "", .id = 13,},
        {.mapKey = "quitCancel", .pos = {100, 1080 +
            20}, .parent = nullptr, .texturePath = "media/gui/quit_cancel.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_cancel_hover.png", .id = 15,},
        {.mapKey = "quitConfirm", .pos = {100 + 387 + 20, 1080 +
            20}, .parent = nullptr, .texturePath = "media/gui/quit_confirm.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_confirm_hover.png", .id = 16,},
        {.mapKey = "newGame", .pos = {500,
            -400}, .parent = nullptr, .texturePath = "media/gui/new_game.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/new_game_hover.png", .id = 17,},
        {.mapKey = "loadGame", .pos = {500,
            -400}, .parent = nullptr, .texturePath = "media/gui/load_game.png", .pressedTexturePath = "", .hoverTexturePath = "media/gui/load_game_hover.png", .id = 18,},});

    _sliders["volume"].background = _driver->getTexture(
        "media/gui/slider_fg.png");
    _sliders["volume"].backgroundBtn = _buttons["volSlider"];
    _sliders["volume"].label = _driver->getTexture(
        "media/gui/slider_label.png");
    _sliders["effects"].background = _driver->getTexture(
        "media/gui/slider_fg.png");
    _sliders["effects"].backgroundBtn = _buttons["effectVolSlider"];
    _sliders["effects"].label = _driver->getTexture(
        "media/gui/effects_slider_label.png");
    _sliders["music"].background = _driver->getTexture(
        "media/gui/slider_fg.png");
    _sliders["music"].backgroundBtn = _buttons["musicVolSlider"];
    _sliders["music"].label = _driver->getTexture(
        "media/gui/music_slider_label.png");

    _transition = AnimatedTexture(_device,
        _driver->getTexture("media/menu_transition_fire2.png"), 5, 7);
    _transition.setPosition(0, 0);
    _transition.addAnimation(0, 30, 20, false, false);
    _transition.setAnimation(0);
    _transition.setScale(1.35, 1.35);

    _overlay = _gui->addInOutFader();
    _overlay->setColor(irr::video::SColor(0, 0, 0, 0));
    _overlay->fadeIn(500);
    _loaded = true;
    return true;
}

void Menu::initButtons(std::initializer_list<struct ButtonProperties> buttons)
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
        _buttons[mapKey].hoverAlpha = 0;
        _buttons[mapKey].hoverWidth = 0;
        if (!button.hoverTexturePath.empty())
            _buttons[mapKey].hoverTexture = _driver->getTexture(
                button.hoverTexturePath.c_str());
    }
}

void Menu::drawButtonsHover()
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

void Menu::switchToOptions()
{
    for (const auto &button: _buttons) {
        if (_buttons["play1p"].button->getAbsolutePosition().UpperLeftCorner.X >
            20 - 1920) {
            button.second.button->move(irr::core::vector2d<irr::s32>{-120, 0});
            _images["background"]->moveRect({2, 0});
            _event.setScrolling(true);
        } else {
            _event.setScrolling(false);
        }
    }
}

void Menu::switchToMenu()
{
    for (const auto &button: _buttons) {
        if (_buttons["play1p"].button->getAbsolutePosition().UpperLeftCorner.X <
            20) {
            button.second.button->move(irr::core::vector2d<irr::s32>{120, 0});
            _images["background"]->moveRect({-2, 0});
            _event.setScrolling(true);
        } else {
            _event.setScrolling(false);
        }
    }
}

void Menu::showQuitButtons()
{
    int speed = -20;
    if (_buttons["quitCancel"].button->getAbsolutePosition().UpperLeftCorner.Y >=
        1080 - 200)
        _buttons["quitCancel"].button->move({0, speed});
    if (_buttons["quitConfirm"].button->getAbsolutePosition().UpperLeftCorner.Y >=
        1080 - 200)
        _buttons["quitConfirm"].button->move({0, speed});
}

void Menu::hideQuitButtons()
{
    int speed = 20;
    if (_buttons["quitCancel"].button->getAbsolutePosition().UpperLeftCorner.Y <=
        1080 + 20)
        _buttons["quitCancel"].button->move({0, speed});
    if (_buttons["quitConfirm"].button->getAbsolutePosition().UpperLeftCorner.Y <=
        1080 + 20)
        _buttons["quitConfirm"].button->move({0, speed});
}

void Menu::update()
{
    if (_event.getState() == "options") {
        switchToOptions();
    } else if (_event.getState() == "menu") {
        switchToMenu();
    }

    if (_event.getState() == "quit") {
        showQuitButtons();
    } else if (_event.getState() == "menu") {
        hideQuitButtons();
    }

    if (_event.getLaunchChoice() == "1p") {
        if (_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner.Y != _buttons["play1p"].button->getAbsolutePosition().UpperLeftCorner.Y) {
            int way = (_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner.Y > _buttons["play1p"].button->getAbsolutePosition().UpperLeftCorner.Y ? -1 : 1);
            _buttons["newGame"].button->move({0, 20 * way});
        }
    } else if (_event.getLaunchChoice() == "2p") {
        if (_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner.Y != _buttons["play2p"].button->getAbsolutePosition().UpperLeftCorner.Y) {
            int way = (_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner.Y > _buttons["play2p"].button->getAbsolutePosition().UpperLeftCorner.Y ? -1 : 1);
            _buttons["newGame"].button->move({0, 20 * way});
        }
    } else {
        if (_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner.Y > -400) {
            _buttons["newGame"].button->move({0, -20});
        }
    }
    _buttons["loadGame"].button->setRelativePosition(_buttons["newGame"].button->getAbsolutePosition().UpperLeftCorner + irr::core::position2d<int>(0, 180));

    if (_overlay->isReady() && _overlay->isVisible()) {
        _overlay->setVisible(false);
    }

    if (_transition.getCurrentFrame() >= 16 && _event._playTransition) {
        _activTab = "board";
        _event._playTransition = false;
    }
    updateSliders();
}

void Menu::updateSliders()
{
    float value;
    float width;

    for (auto &slider: _sliders) {
        if (_event.MouseState.leftButtonDown &&
            slider.second.backgroundBtn.button->getAbsolutePosition().isPointInside(
                _event.MouseState.position)) {
            value = (_event.MouseState.position.X -
                slider.second.backgroundBtn.button->getAbsolutePosition().UpperLeftCorner.X);
            width =
                slider.second.backgroundBtn.button->getAbsolutePosition().LowerRightCorner.X -
                    slider.second.backgroundBtn.button->getAbsolutePosition().UpperLeftCorner.X;
            slider.second.value = value / width * 100;
            if (slider.first == "volume") {
                _AudioManager->manageVolume(slider.second.value, Global);
            } else if (slider.first == "music") {
                _AudioManager->manageVolume(slider.second.value, Music);
            } else if (slider.first == "effects") {
                _AudioManager->manageVolume(slider.second.value, Effects);
            }
        }
    }
}

void Menu::drawSliders()
{
    for (const auto &slider: _sliders) {
        _driver->draw2DImage(slider.second.background, slider.second.backgroundBtn.button->getAbsolutePosition().UpperLeftCorner,
            irr::core::rect<irr::s32>(0, 0,
                slider.second.background->getSize().Width *
                    slider.second.value / 100,
                slider.second.background->getSize().Height), 0,
            irr::video::SColor(255, 255, 255, 255), true);
        _driver->draw2DImage(slider.second.label, slider.second.backgroundBtn.button->getAbsolutePosition().UpperLeftCorner - irr::core::vector2d<int>(slider.second.label->getSize().Width + 10, -((slider.second.background->getSize().Height - slider.second.label->getSize().Height) / 2)),
                             irr::core::rect<irr::s32>(0, 0,
                                                       slider.second.label->getSize().Width,
                                                       slider.second.label->getSize().Height), 0,
                             irr::video::SColor(255, 255, 255, 255), true);
    }
}

void Menu::draw()
{
    _images["background"]->draw();
    _gui->drawAll();
    drawButtonsHover();
    drawSliders();
    if (_event._playTransition)
        _transition.play();
}
