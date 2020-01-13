/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <irrlicht/irrlicht.h>
#include <string>
#include <algorithm>
#include "../core/AudioManager.hpp"

class Entity {
    public:
    Entity(irr::IrrlichtDevice *, irr::scene::IMetaTriangleSelector *,
        irr::io::path, AudioManager *,
        irr::core::vector3df = {0.0f, 0.0f, 0.0f},
        irr::core::vector3df = {0.0f, 0.0f, 0.0f}, irr::f32 = 1.0f
    );

    void setTexture(irr::io::path path);
    void setAnim(irr::scene::EMD2_ANIMATION_TYPE);
    irr::core::vector3df getPos() const;
    void move(irr::f32, irr::f32);
    irr::scene::IAnimatedMeshSceneNode *getMesh() const;

    protected:
    irr::IrrlichtDevice *_device;
    irr::video::ITexture *_texture;
    irr::scene::IAnimatedMeshSceneNode *_mesh;
    irr::scene::IMetaTriangleSelector *_meta;
    AudioManager *_AudioManager;
};

#endif