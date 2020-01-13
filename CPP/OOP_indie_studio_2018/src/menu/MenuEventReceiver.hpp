/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef MENUEVENTRECEIVER_H
#define MENUEVENTRECEIVER_H

#include <string>
#include <irrlicht/irrlicht.h>

class MenuEventReceiver : public irr::IEventReceiver {
    public:
    enum Buttons {
        BEGIN,
        SINGLEPLAYER,
        MULTIPLAYER,
        OPTIONS,
        QUIT,
        BACK_TO_MENU,
        VOLUME_DOWN,
        VOLUME_SLIDER,
        VOLUME_UP,
        EFFECT_VOLUME_DOWN,
        EFFECT_VOLUME_SLIDER,
        EFFECT_VOLUME_UP,
        MUSIC_VOLUME_DOWN,
        MUSIC_VOLUME_SLIDER,
        MUSIC_VOLUME_UP,
        QUIT_CANCEL,
        QUIT_CONFIRM,
        NEW_GAME,
        LOAD_GAME,
        COUNT
    };
    struct SMouseState {
        irr::core::position2di position;
        bool leftButtonDown = false;
    } MouseState;

    MenuEventReceiver(irr::IrrlichtDevice *, std::string &,
        AudioManager *AudioManager, bool *multiplayer
    );

    std::string getState() const;

    unsigned int getGameVolume() const;

    unsigned int getGameEffectsVolume() const;

    unsigned int getMusicVolume() const;

    void setMusicVolume(unsigned int volume);

    void setVolume(unsigned int volume);

    void setEffectVolume(unsigned int volume);

    bool OnEvent(const irr::SEvent &event) override;

    bool _playTransition = false;

    void setState(const std::string &state);

    void setScrolling(bool scrolling);

    bool isScrolling() const;

    const std::string &getLaunchChoice() const;

    void setLaunchChoice(const std::string &launchChoice);
private:
    unsigned int _volume = 100;
    unsigned int _effectsVolume = 100;
    unsigned int _musicVolume = 100;
    std::string _state = "";
    std::string _launchChoice = "";

private:
    irr::IrrlichtDevice *_device;
    irr::gui::IGUIEnvironment *_gui;
    std::string &_activTab;
    AudioManager *_AudioManager;
    bool *_multiplayer;
    bool _scrolling = false;
};

#endif