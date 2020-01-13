/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** WinScreen.hpp
*/

#include <string>
#include "../core/Tab.hpp"
#include "../core/AudioManager.hpp"
#include "WinScreenEventReceiver.hpp"
#include "../animatedTexture/AnimatedTexture.hpp"
#include <irrlicht/irrlicht.h>

#ifndef INDIE_STUDIO_WINSCREEN_HPP
#define INDIE_STUDIO_WINSCREEN_HPP

class WinScreen : public Tab {
public:
    WinScreen(irr::IrrlichtDevice *, std::string &, AudioManager *);

    ~WinScreen();

    bool init() override;
    void update() override;
    void draw() override;
    void unload() override;

    enum ButtonId {
        BEGIN,
        TO_MENU,
        COUNT,
    };

private:
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
    void drawButtonsHover();
    void initButtons(std::initializer_list<struct ButtonProperties> buttons);
    std::map<std::string, Button> _buttons;
    AudioManager *_audio;
    AnimatedTexture _transition;
    AnimatedTexture _happyBomberman;
    WinScreenEventReceiver _event;
    std::map<std::string, irr::video::ITexture *> _textures;
    irr::gui::IGUIInOutFader *_overlay;
    bool _hasFaded;
};

#endif //INDIE_STUDIO_WINSCREEN_HPP
