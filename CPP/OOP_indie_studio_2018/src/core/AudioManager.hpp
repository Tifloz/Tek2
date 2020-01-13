/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** Created by Florian Louvet,
*/
#ifndef INDIE_STUDIO_AUDIOMANAGER_HPP
#define INDIE_STUDIO_AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <map>

enum Songs {
    Playing,
    Main,
    Victory,
    Death
};

enum FX {
    Explosion,
    Walk,
    Click,
    Transition,
    PowerUp
};

enum Type {
    Global,
    Effects,
    Music
};

class AudioManager {
    public:
    AudioManager();

    void manageVolume(float volume, Type channel);

    void initSoundBuffer(const std::string &path, FX type);

    void Play(FX sound);

    void Play(Songs sound);

    void initMusic(const std::string &path, Songs type, bool loop = false);

    void Stop(FX sound);

    void Stop(Songs sound);

    virtual ~AudioManager();

    private:
    std::map<Songs, std::unique_ptr<sf::Music>> _Songs;
    std::map<FX, std::map<sf::Sound *, sf::SoundBuffer>> _Effects;

    float _globalSound{};
    float _effectsSound{};
    float _musicSound{};
};

#endif //INDIE_STUDIO_AUDIOMANAGER_HPP
