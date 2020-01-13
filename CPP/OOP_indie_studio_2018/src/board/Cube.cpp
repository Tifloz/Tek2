/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Cube.hpp"

Cube::Cube(irr::IrrlichtDevice *device, irr::scene::IMetaTriangleSelector *meta, int id, irr::io::path path, irr::core::vector3df pos) :
_device(device), _meta(meta), _mesh(device->getSceneManager()->addCubeSceneNode(10.f, 0, id, pos))
{
    _mesh->setMaterialTexture(0, device->getVideoDriver()->getTexture(path));
    _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    irr::scene::ITriangleSelector *selector = device->getSceneManager()->createTriangleSelectorFromBoundingBox(_mesh);
    meta->addTriangleSelector(selector);
    selector->drop();
}

Cube::~Cube()
{
}

bool Cube::isHit() const
{
    return _mesh->isVisible();
}

