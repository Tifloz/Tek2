/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include <tgmath.h>
#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice *device, irr::scene::IMetaTriangleSelector *meta,
    irr::io::path path, AudioManager *AudioManager, irr::core::vector3df pos,
    int player, int radius) :
Entity(device, meta, path, AudioManager, {std::floor((pos.X + 5) / 10) * 10, std::floor((pos.Y + 5) / 10) * 10, std::floor((pos.Z + 5) / 10) * 10}, {-90.0f, 0.0f, -90.0f}, 2.f),
_device(device), _timer(device->getTimer()), _blast(_timer->getTime() + 1000), _end(_blast + (500 * radius)), _radius(radius * 2), _blasted(false), _player(player)
{
    std::string particlesPath = "media/menu.jpg";

    std::vector<struct emitterProperties> directions = {
        {
            .direction = "left",
            .directionVector = {irr::core::vector3df(-0.06f, 0.0f, -0.0f)}
        },
        {
            .direction = "right",
            .directionVector = {irr::core::vector3df(0.06f, 0.0f, -0.0f)}
        },
        {
            .direction = "up",
            .directionVector = {irr::core::vector3df(0.0f, 0.06f, -0.0f)}
        },
        {
            .direction = "down",
            .directionVector = {irr::core::vector3df(0.0f, -0.06f, -0.0f)}
        }
    };
    for (const auto &direction: directions) {
        _beams[direction.direction].directionVector = direction.directionVector;
        _beams[direction.direction].particleNode = _device->getSceneManager()->addParticleSystemSceneNode(false);
        _beams[direction.direction].emitter = _beams[direction.direction].particleNode->createBoxEmitter(
            irr::core::aabbox3d<irr::f32>(-1, 1, -1, 1, 1, 1),
            irr::core::vector3df(0, 0, 0),
            80, 100,
            irr::video::SColor(0, 255, 255, 255),
            irr::video::SColor(255, 255, 255, 255),
            200, 1500, 180,
            irr::core::dimension2df(1.f, 1.f),
            irr::core::dimension2df(2.f, 2.f));
        _beams[direction.direction].affector = _beams[direction.direction].particleNode->createFadeOutParticleAffector();
        _beams[direction.direction].particleNode->setPosition(_mesh->getPosition());
        _beams[direction.direction].particleNode->setScale(irr::core::vector3df(2, 2, 2));
        _beams[direction.direction].particleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _beams[direction.direction].particleNode->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
        _beams[direction.direction].particleNode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
        _beams[direction.direction].particleNode->setMaterialTexture(0,
            _device->getVideoDriver()->getTexture("media/smoke_particle.png"));
        _beams[direction.direction].sphere = _device->getSceneManager()->addSphereSceneNode(5, 16, 0, -1, _mesh->getPosition(), irr::core::vector3df(0, 0, 0),irr::core::vector3df(0.75f, 0.75f, 0.75f));
        _beams[direction.direction].sphere->setVisible(false);
        _beams[direction.direction].sParticleNode = _device->getSceneManager()->addParticleSystemSceneNode(false);
        _beams[direction.direction].sEmitter = _beams[direction.direction].particleNode->createSphereEmitter(
            irr::core::vector3df(0, 0, 0), 3, irr::core::vector3df(0, 0, 0),
            200, 400, irr::video::SColor(0, 255, 255, 255),
            irr::video::SColor(255, 255, 255, 255),
            200, 500, 180,
            irr::core::dimension2df(1.f, 1.f),
            irr::core::dimension2df(2.f, 2.f)
        );
        _beams[direction.direction].sParticleNode->setPosition(_mesh->getPosition());
        _beams[direction.direction].sParticleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _beams[direction.direction].sParticleNode->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
        _beams[direction.direction].sParticleNode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
        _beams[direction.direction].sParticleNode->setMaterialTexture(0,
            _device->getVideoDriver()->getTexture("media/fire_particle.png"));
    }
    _particleNode = _device->getSceneManager()->addParticleSystemSceneNode(false);
    _emitter = _particleNode->createBoxEmitter(
            irr::core::aabbox3d<irr::f32>(-1, 1, -1, 1, 1, 1),
            irr::core::vector3df(0, 0, 0),
            100, 120,
            irr::video::SColor(0, 255, 255, 255),
            irr::video::SColor(255, 255, 255, 255),
            200, 1500, 180,
            irr::core::dimension2df(10.f, 10.f),
            irr::core::dimension2df(15.f, 15.f));
    _affector = _particleNode->createFadeOutParticleAffector(10);
    _particleNode->addAffector(_affector);
    _particleNode->setPosition(Bomb::getMesh()->getPosition());
    _particleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _particleNode->setMaterialTexture(0,
        _device->getVideoDriver()->getTexture("media/fire_particle.png"));
    _particleNode->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

Bomb::~Bomb()
{
    _mesh->remove();
    for (auto &beam: _beams) {
        beam.second.particleNode->setEmitter(nullptr);
        beam.second.sParticleNode->setEmitter(nullptr);
        beam.second.sphere->remove();
    }
}

bool Bomb::update()
{
    if (_timer->getTime() >= _blast + 100) {
        _particleNode->setEmitter(nullptr);
    }
    if (_timer->getTime() >= _blast + 300) {
        _light->setVisible(false);
    }
    if (!_blasted && _timer->getTime() >= _blast) {
        _blasted = true;
        _mesh->setVisible(false);
        _AudioManager->Play(Explosion);
        for (auto &beam: _beams) {
            beam.second.particleNode->setEmitter(beam.second.emitter);
            beam.second.emitter->drop();
            beam.second.sParticleNode->setEmitter(beam.second.sEmitter);
            beam.second.sEmitter->drop();
            beam.second.sphere->setVisible(true);
        }
        _particleNode->setEmitter(_emitter);
        _light = _device->getSceneManager()->addLightSceneNode(0, Bomb::getMesh()->getPosition());
        _emitter->drop();
    } else if (_blasted && _timer->getTime() >= _end) {
        return false;
    } else if (_blasted) {
        for (auto &beam: _beams) {
            irr::core::vector3df newPosition = beam.second.sphere->getPosition() + beam.second.directionVector * 15;
            beam.second.sphere->setPosition(newPosition);
            beam.second.particleNode->setPosition(newPosition);
            beam.second.sParticleNode->setPosition(newPosition);
            beam.second.hit = false;
        }
    }
    return true;
}

bool Bomb::hasExploded() const
{
    return _blasted;
}

std::map<std::string, Beam> Bomb::getBeams() const
{
    return _beams;
}

int Bomb::getPlayer() const
{
    return _player;
}

void Bomb::eraseBeam(std::map<std::string, Beam>::iterator it)
{
    Beam beam = it->second;

    beam.sphere->setVisible(false);
    beam.particleNode->setVisible(false);
    beam.sParticleNode->setVisible(false);
}