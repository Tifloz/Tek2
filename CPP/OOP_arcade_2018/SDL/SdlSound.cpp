/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by Florian Louvet,
*/
#include "SdlSound.hpp"

SdlSound::SdlSound(std::string sound)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
            Mix_GetError());
    }
    music = Mix_LoadMUS(sound.c_str());
    if (music == nullptr) {
        printf("Failed to load beat music! SDL_mixer Error: %s\n",
            Mix_GetError());
    }
}

SdlSound::~SdlSound()
{
    Mix_FreeMusic(music);
    Mix_Quit();
}

bool SdlSound::play()
{
    if (!isLooping)
        Mix_PlayMusic(music, 1);
    else
        Mix_PlayMusic(music, -1);
    this->isPlay = true;
    return true;
}

bool SdlSound::reset()
{
    Mix_HaltMusic();
    Mix_PlayMusic(music, 1);
    return true;
}

bool SdlSound::setLoop(bool activate)
{
    isLooping = activate;
    return true;
}

bool SdlSound::isLoop()
{
    return isLooping;
}

bool SdlSound::stop()
{
    Mix_HaltMusic();
    return true;
}

bool SdlSound::isRunning()
{
    return Mix_PlayingMusic() != 0;
}

void SdlSound::setVolume(size_t volume)
{
    Mix_Volume(-1, static_cast<int>(volume));
}

size_t SdlSound::getVolume()
{
    return static_cast<size_t>(Mix_Volume(-1, -1));
}
