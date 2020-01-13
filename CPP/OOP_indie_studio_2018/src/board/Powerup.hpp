/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef POWERUP_H
#define POWERUP_H

#include <irrlicht/irrlicht.h>
#include "Entity.hpp"
#include "../core/AudioManager.hpp"


class Powerup : public Entity
{
public:
    enum Type {
        STOCK,
        SPEED,
        RANGE,
        GHOST,
    };

    Powerup(
        irr::IrrlichtDevice *device,
        irr::scene::IMetaTriangleSelector *meta,
        AudioManager *audio,
        Powerup::Type type,
        irr::io::path path,
        irr::core::vector3df,
        irr::core::vector3df = {0.f, 0.f, 0.f},
        irr::f32 = 1.f
    );
    ~Powerup();

    bool update();
    Type getType() const;
    void setTaken(bool);

private:
    Type _type;
    irr::u32 _end;
    bool _taken;
};

#endif