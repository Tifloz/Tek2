/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Powerup.hpp"

Powerup::Powerup(irr::IrrlichtDevice *device, irr::scene::IMetaTriangleSelector *meta, AudioManager *audio, Powerup::Type type, irr::io::path path, irr::core::vector3df pos, irr::core::vector3df rot, irr::f32 scale) :
Entity(device, meta, path, audio, pos, rot, scale), _type(type), _end(device->getTimer()->getTime() + 15000), _taken(false)
{
}

Powerup::~Powerup()
{
    _meta->removeTriangleSelector(_mesh->getTriangleSelector());
    _mesh->remove();
}

bool Powerup::update()
{
    if (_taken || _device->getTimer()->getTime() >= _end)
        return false;
    irr::core::vector3df rot = _mesh->getRotation();
    rot.Z += 90 * (1.0 / _device->getVideoDriver()->getFPS());
    _mesh->setRotation(rot);
    return true;
}

Powerup::Type Powerup::getType() const
{
    return _type;
}

void Powerup::setTaken(bool state)
{
    _taken = state;
}