/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Player.hpp"

Player::Player(int id, irr::IrrlichtDevice *device, const irr::io::path &path,
    const irr::core::vector3df &pos, bool human,
    irr::scene::IMetaTriangleSelector *meta, AudioManager *AudioManager
) : Entity(device, meta, path, AudioManager, pos, {0.0f, 0.0f, -90.0f}, 1),
    _id(id), _alive(true), _human(human)
{
    _buffs = {{Powerup::STOCK, {false, 0}}, {Powerup::SPEED, {false, 0}},
        {Powerup::RANGE, {false, 0}}, {Powerup::GHOST, {false, 0}}};
}

Player::~Player()
{
}

void Player::setAlive(bool state)
{
    _alive = state;
}

bool Player::isAlive() const
{
    return _alive;
}

bool Player::isHuman() const
{
    return _human;
}

void Player::setAction(const std::string &key, bool state)
{
    if (_actions[key] == state)
        return;
    _actions[key] = state;
    if (key == "bomb")
        return;
    int cnt = 0;
    for (const auto &action : _actions)
        if (action.first != "bomb" && action.second)
            cnt++;
    if (_alive) {
    if (cnt == 1) {
        _AudioManager->Play(Walk);
        _mesh->setFrameLoop(50, 76);
        _mesh->setAnimationSpeed(40);
    } else {
        _AudioManager->Stop(Walk);
        _mesh->setFrameLoop(0, 46);
        _mesh->setAnimationSpeed(20);
        }
    }
}

void Player::update(std::vector<Bomb *> &bombs, std::vector<Powerup *> &powerups)
{
    int cnt = 0;
    std::string dir;

    handlePowerups(powerups);
    for (const auto &action : _actions)
        if (action.first != "bomb" && action.second) {
            cnt++;
            dir = action.first;
        }
    if (cnt == 1) {
        irr::f32 dt = 1.0f / _device->getVideoDriver()->getFPS();
        irr::f32 speed = 50.f + 25 * _buffs[Powerup::SPEED].first;
        if (dir == "up") {
            move(0.0f, speed * dt);
            _mesh->setRotation({0.0f, 0.0f, 90.0f});
        } else if (dir == "left") {
            move(-1 * speed * dt, 0.0f);
            _mesh->setRotation({0.0f, 0.0f, 180.0f});
        } else if (dir == "down") {
            move(0.f, -1 * speed * dt);
            _mesh->setRotation({0.0f, 0.0f, 270.0f});
        } else if (dir == "right") {
            move(speed * dt, 0.f);
            _mesh->setRotation({0.0f, 0.0f, 0.0f});
        }
    }
    if (_actions["bomb"] && hasBombs(bombs)) {
        bool found = false;
        irr::core::vector3df actualPos = {std::floor((getPos().X + 5) / 10) * 10,
            std::floor((getPos().Y + 5) / 10) * 10,
            std::floor((getPos().Z + 5) / 10) * 10};
        for (auto bomb : bombs)
            if (bomb->getPos() == actualPos)
                found = true;
        if (!found)
            bombs.push_back(
                new Bomb(_device, _meta, "media/Bomb.obj", _AudioManager,
                    _mesh->getPosition(), _id,
                    1 + _buffs[Powerup::RANGE].first));
    }
}

void Player::handlePowerups(std::vector<Powerup *> &powerups)
{
    for (auto powerup : powerups)
        if (_mesh->getTransformedBoundingBox().intersectsWithBox(powerup->getMesh()->getTransformedBoundingBox())) {
            _buffs[powerup->getType()].first = true;
            _buffs[powerup->getType()].second = _device->getTimer()->getTime() + 2000;
            powerup->setTaken(true);
        }
    if (_buffs[Powerup::STOCK].first && _device->getTimer()->getTime() >= _buffs[Powerup::STOCK].second)
        _buffs[Powerup::STOCK].first = false;
    if (_buffs[Powerup::SPEED].first && _device->getTimer()->getTime() >= _buffs[Powerup::SPEED].second)
        _buffs[Powerup::SPEED].first = false;
    if (_buffs[Powerup::RANGE].first && _device->getTimer()->getTime() >= _buffs[Powerup::RANGE].second)
        _buffs[Powerup::RANGE].first = false;
    if (_buffs[Powerup::GHOST].first && _device->getTimer()->getTime() >= _buffs[Powerup::GHOST].second)
        _buffs[Powerup::GHOST].first = false;
}

bool Player::hasBombs(std::vector<Bomb *> &bombs) const
{
    int cnt = 0;
    for (auto bomb : bombs) {
        if (bomb->getPlayer() == _id)
            cnt++;
    }
    return (cnt < 2 + _buffs.at(Powerup::STOCK).first);
}

int Player::getId() const {
    return _id;
}
