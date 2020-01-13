//
// Created by gauthierbetaucourt on 5/16/19.
//

#ifndef OOP_INDIE_STUDIO_2018_MENU_HPP
#define OOP_INDIE_STUDIO_2018_MENU_HPP

#include <irrlicht/ITexture.h>
#include "../input.hpp"
#include "../core/Tab.hpp"
#include "../animatedTexture/AnimatedTexture.hpp"
#include "MenuEventReceiver.hpp"

#include <irrlicht/irrlicht.h>

class Menu : public Tab {
public:
    Menu(irr::IrrlichtDevice *, std::string &, AudioManager *, bool *);

    ~Menu();

    bool init();

    void update();

    void draw();

    void unload();
private:
    void switchToOptions();
    void switchToMenu();
    void showQuitButtons();
    void hideQuitButtons();
    void drawButtonsHover();
    void drawSliders();
    void updateSliders();
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
        irr::video::ITexture *hoverTexture;
        unsigned short hoverAlpha;
        unsigned int hoverWidth;
    };
    void initButtons(std::initializer_list<ButtonProperties> buttons);
    MenuEventReceiver _event;
    std::map<std::string, struct Button> _buttons;

    struct Slider {
        irr::video::ITexture *background;
        irr::video::ITexture *label;
        Button backgroundBtn;
        unsigned int value = 100;
    };
    std::map<std::string, struct Slider> _sliders;

    AnimatedTexture _transition;

    irr::gui::IGUIInOutFader *_overlay;
};

#endif //OOP_INDIE_STUDIO_2018_MENU_HPP
