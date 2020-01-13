/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** Created by Florian Louvet,
*/
#include <iostream>
#include "AudioManager.hpp"

void AudioManager::initSoundBuffer(const std::string &path, FX type)
{
    sf::SoundBuffer buffer;
    auto *player = new sf::Sound;
    if (!buffer.loadFromFile(path)) {
        perror("A sound was not found");
        exit(84);
    }
    this->_Effects[type].insert(std::make_pair(player, buffer));
    for (auto &it : _Effects[type])
        it.first->setBuffer(it.second);
}

void AudioManager::initMusic(const std::string &path, Songs type, bool loop)
{
    auto music = std::unique_ptr<sf::Music>(new sf::Music);
    if (!music->openFromFile(path)) {
        perror("A sound was not found");
        exit(84);
    }
    music->setLoop(loop);
    this->_Songs.insert(std::make_pair(type, std::move(music)));
}

AudioManager::AudioManager()
{
    this->_effectsSound = 100;
    this->_musicSound = 100;
    this->_globalSound = 1;
    initSoundBuffer("media/songs/Explosion.wav", Explosion);
    initSoundBuffer("media/songs/Walk.wav", Walk);
    initSoundBuffer("media/songs/Transition.wav", Transition);
    initSoundBuffer("media/songs/PowerUp.wav", PowerUp);
    initSoundBuffer("media/songs/Click.wav", Click);
    //initMusic("media/songs/Game.wav", Playing, true);
    //initMusic("media/songs/Menu.wav", Main, true);
    //initMusic("media/songs/Victory.wav", Victory);
    //initMusic("media/songs/Death.wav", Death);
}

void AudioManager::Play(FX sound)
{
    for (auto &it : _Effects[sound])
        it.first->setVolume(this->_effectsSound * this->_globalSound);
    if (sound == Walk) {
        for (auto &it : _Effects[sound])
            if (it.first->getStatus() == sf::Music::Stopped)
                it.first->play();
    } else {
        for (auto &it : _Effects[sound])
            it.first->play();
    }
}

void AudioManager::Play(Songs sound)
{
    this->_Songs[sound]->setVolume(this->_musicSound * this->_globalSound);
    this->_Songs[sound]->play();
}

void AudioManager::Stop(FX sound)
{
    for (auto &it : _Effects[sound]) {
        it.first->stop();
    }
}

void AudioManager::Stop(Songs sound)
{
    this->_Songs[sound]->stop();
}

AudioManager::~AudioManager()
{
    for (auto &_Song : _Songs) {
        _Song.second->stop();
    }
    for (auto &_Effect : _Effects) {
        for (auto &it2 : _Effect.second) {
            it2.first->stop();
            delete it2.first;
        }
    }
}

void AudioManager::manageVolume(float volume, Type channel)
{
    switch (channel) {
    case Global:
        this->_globalSound = volume / 100;
        for (auto &it : _Effects)
            for (auto &it2 : it.second)
                it2.first->setVolume(this->_effectsSound * this->_globalSound);
        for (auto &_Song : _Songs) {
            _Song.second->setVolume(this->_musicSound * this->_globalSound);
        }
        break;
    case Effects:
        this->_effectsSound = volume;
        for (auto &it : _Effects)
            for (auto &it2 : it.second)
                it2.first->setVolume(this->_effectsSound * this->_globalSound);
        break;
    case Music:
        this->_musicSound = volume;
        for (auto &_Song : _Songs)
            _Song.second->setVolume(this->_musicSound * this->_globalSound);
        break;
    }
}