/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#ifndef BOMB_H
#define BOMB_H

#include <vector>
#include <map>
#include <irrlicht/irrlicht.h>
#include <memory>
#include "Entity.hpp"
#include "Map.hpp"

struct Beam {
    irr::scene::ISceneNode *sphere;
    irr::core::vector3df directionVector;
    irr::scene::IParticleSystemSceneNode *particleNode;
    irr::scene::IParticleSystemSceneNode *sParticleNode;
    irr::scene::IParticleSphereEmitter *sEmitter;
    irr::scene::IParticleBoxEmitter *emitter;
    irr::scene::IParticleAffector *affector;
    bool hit;
};

class Bomb : public Entity
{
public:
    Bomb(irr::IrrlichtDevice *device, irr::scene::IMetaTriangleSelector *,irr::io::path path, AudioManager *AudioManager, irr::core::vector3df,int player, int radius = 2);
    ~Bomb();

    bool update();
    bool hasExploded() const;
    std::map<std::string, Beam> getBeams() const;
    int getPlayer() const;
    void eraseBeam(std::map<std::string, Beam>::iterator);

private:
    irr::IrrlichtDevice *_device;
    irr::ITimer *_timer;
    irr::u32 _blast;
    irr::u32 _end;
    int _radius;
    bool _blasted;
    struct emitterProperties {
        std::string direction;
        irr::core::vector3df directionVector;
    };
    std::map<std::string, Beam> _beams;
    int _player;

    irr::scene::IParticleSystemSceneNode *_particleNode;
    irr::scene::IParticleBoxEmitter *_emitter;
    irr::scene::IParticleAffector *_affector;

    irr::scene::ILightSceneNode *_light;
};

#endif