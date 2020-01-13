/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef CUBE_H
#define CUBE_H

#include <irrlicht/irrlicht.h>

class Cube
{
    public:
    Cube(irr::IrrlichtDevice *device, irr::scene::IMetaTriangleSelector *meta, int id, irr::io::path path, irr::core::vector3df pos);
    ~Cube();

    bool isHit() const;

    private:
    irr::IrrlichtDevice *_device;
    irr::scene::IMetaTriangleSelector *_meta;
    irr::scene::IMeshSceneNode *_mesh;
};

#endif