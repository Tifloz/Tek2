/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Entity.hpp"

Entity::Entity(irr::IrrlichtDevice *device,
    irr::scene::IMetaTriangleSelector *meta,
    irr::io::path path, AudioManager *AudioManager,
    irr::core::vector3df pos,
    irr::core::vector3df rot,
    irr::f32 scale) : _device(device), _meta(meta), _AudioManager(AudioManager)
{
    if (path == "bomb")
        _mesh = device->getSceneManager()->addAnimatedMeshSceneNode(
            device->getSceneManager()->getMesh("media/sydney.md2"), 0, -1, pos,
            rot, {0, 0, 0});
    else
        _mesh = device->getSceneManager()->addAnimatedMeshSceneNode(device->getSceneManager()->getMesh(path), 0, -1, pos, rot, {scale, scale, scale});
    _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

irr::core::vector3df Entity::getPos() const
{
    return _mesh->getPosition();
}

void Entity::move(irr::f32 dx, irr::f32 dy)
{
    irr::core::vector3df pos = getPos();
    pos.X += dx;
    pos.Y += dy;

    _mesh->setPosition(pos);
}

void Entity::setTexture(irr::io::path path)
{
    _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _texture = _device->getVideoDriver()->getTexture(path);
    _mesh->setMaterialTexture(0, _texture);
}

void Entity::setAnim(irr::scene::EMD2_ANIMATION_TYPE anim)
{
    _mesh->setMD2Animation(anim);
}

irr::scene::IAnimatedMeshSceneNode *Entity::getMesh() const
{
    return _mesh;
}