/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#ifndef OOP_ARCADE_2018_SDLSOUND_HPP
#define OOP_ARCADE_2018_SDLSOUND_HPP

#include <SDL2/SDL_audio.h>
#include <ISound.hpp>
#include <iostream>
#include <SDL2/SDL_mixer.h>

class SdlSound : ISound {
    public:
    SdlSound(std::string sound);

    virtual ~SdlSound();

    bool play();

    bool reset();

    bool setLoop(bool activate);

    bool isLoop();

    bool stop();

    bool isRunning();

    void setVolume(size_t);

    size_t getVolume();

    private:
    Mix_Music *music;
    bool isPlay;
    bool isLooping;
};

#endif //OOP_ARCADE_2018_SDLSOUND_HPP
