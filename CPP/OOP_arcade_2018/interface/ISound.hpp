/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Interface for OOP_arcade_2018
*/

#ifndef ARCADE_ISOUND_HPP
#define ARCADE_ISOUND_HPP

#include <string>
#include <cstddef>

class ISound {
	public:
        	virtual ~ISound() = default;
        	virtual bool play() = 0;
       		virtual bool reset() = 0;
        	virtual bool setLoop(bool activate) = 0;
        	virtual bool isLoop() const = 0;
        	virtual bool stop() = 0;
        	virtual bool isRunning() const = 0;
        	virtual void setVolume(size_t) = 0;
        	virtual size_t getVolume() const = 0;
};

#endif //ARCADE_ISOUND_HPP
