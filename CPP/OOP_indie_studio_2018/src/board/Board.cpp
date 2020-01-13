/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Created by Denis Demouveau,
*/

#include "Board.hpp"
#include "ai.hpp"

Board::Board(irr::IrrlichtDevice *device, std::string &activTab, AudioManager *AudioManager, bool *multiplayer
) : Tab(device, activTab, AudioManager), _audio(AudioManager), _event(BoardEventReceiver(device, activTab, _map, _players)), _timer(_device->getTimer()), _lastPowerup(_timer->getTime())
{
    _manager = _device->getSceneManager();
    _multiplayer = multiplayer;
}

Board::~Board()
{
    if (_loaded) {
        for (auto player : _players)
            delete player;
        for (auto bomb : _bombs)
            delete bomb;
        _meta->drop();
    }
}

void Board::unload()
{
    std::cout << "Unloading Board" << std::endl;
    if (_loaded) {
        _players.clear();
        _meta->drop();
        _map.clear();
        _bombs.clear();
    }
    _gui->clear();
    _buttons.clear();
    _powerups.clear();
    _isWon = false;
    _playEndingTransition = false;
    _loaded = false;
}

bool Board::init()
{
    _lastPowerup = _timer->getTime();
    _meta = _manager->createMetaTriangleSelector();
    if (!_map.init("Map.txt"))
        return false;
    createPlayers();
    initMap();
    for (size_t x = 0 ; x < _map.cols() ; x++) {
        addWall(x, -1);
        addWall(x, _map.rows());
    }
    for (size_t y = 0 ; y < _map.rows() ; y++) {
        addWall(-1, y);
        addWall(_map.cols(), y);
    }
    for (auto player : _players) {
        irr::scene::ISceneNodeAnimator *animator = _manager->createCollisionResponseAnimator(_meta,player->getMesh(), irr::core::vector3df(2, 2, 2),irr::core::vector3df(0, 0, 0));
        player->getMesh()->addAnimator(animator);
        animator->drop();
    }
    _manager->addCameraSceneNode(0,
        irr::core::vector3df(_map.cols() / 2 * 10, _map.rows() / 2 * 10, -100.0f),
        irr::core::vector3df(_map.cols() / 2 * 10, _map.rows() / 2 * 10, 400000.0f)
    );
    _device->setEventReceiver(&_event);
    _transition = AnimatedTexture(_device,
        _driver->getTexture("media/menu_transition_fire2.png"), 5, 7);
    _transition.setPosition(0, 0);
    _transition.addAnimation(16, 30, 20, false, false);
    _transition.setAnimation(0);
    _transition.setScale(1.35, 1.35);
    _manager->addLightSceneNode(0, irr::core::vector3df(0, 0, -200), irr::video::SColor(255, 255, 255, 255), 100);

    _endingTransition = AnimatedTexture(_device,
        _driver->getTexture("media/menu_transition_fire2.png"), 5, 7);
    _endingTransition.setPosition(0, 0);
    _endingTransition.addAnimation(0, 30, 20, false, false);
    _endingTransition.setAnimation(0);
    _endingTransition.setScale(1.35, 1.35);

    //PAUSE MENU
    initButtons({
                        {
                                .mapKey = "resume",
                                .pos = {1920 / 2 - 381 / 2, 20},
                                .parent = 0, .texturePath = "media/gui/resume.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/resume_hover.png",
                                .id = ButtonId::RESUME
                        },
                        {
                                .mapKey = "save",
                                .pos = {1920 / 2 - 381 / 2, 178 + 40},
                                .parent = 0, .texturePath = "media/gui/save.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/save_hover.png",
                                .id = ButtonId::SAVE
                        },
                        {
                                .mapKey = "quitMenu",
                                .pos = {1920 / 2 - 381 / 2, 178 * 2 + 60},
                                .parent = 0, .texturePath = "media/gui/quit_to_menu.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_to_menu_hover.png",
                                .id = ButtonId::QUIT_TO_MENU
                        },
                        {
                                .mapKey = "quitDesktop",
                                .pos = {1920 / 2 - 381 / 2, 178 * 3 + 80},
                                .parent = 0, .texturePath = "media/gui/quit_to_desktop.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_to_desktop_hover.png",
                                .id = ButtonId::QUIT_TO_DESKTOP
                        },
                        {
                                .mapKey = "quitConfirm",
                                .pos = {2000, 178 * 3 + 60},
                                .parent = 0, .texturePath = "media/gui/quit_confirm.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_confirm_hover.png",
                                .id = ButtonId::QUIT_CONFIRM
                        },
                        {
                                .mapKey = "quitCancel",
                                .pos = {2000, 178 * 3 + 60},
                                .parent = 0, .texturePath = "media/gui/quit_cancel.png",
                                .pressedTexturePath = "", .hoverTexturePath = "media/gui/quit_cancel_hover.png",
                                .id = ButtonId::QUIT_CANCEL
                        },
                });
    _textures["textQuitToMenu"] = _driver->getTexture(
        "media/gui/text_quit_to_menu.png");
    _textures["textQuitToDesktop"] = _driver->getTexture(
        "media/gui/text_quit_to_desktop.png");

    _loaded = true;
    return true;
}

void Board::initMap()
{
    irr::s32 id;
    for (size_t y = 0; y < _map.rows(); y++)
        for (size_t x = 0; x < _map.cols(); x++) {
            _ground.push_back(new Cube(_device, _meta, -1, "media/grass.png",
                irr::core::vector3df(x * 10.f, y * 10.f, 10.f)));
            id = y * _map.rows() + x;
            char tile = _map.getTile(x, y);
            if (tile == '+' || tile == 'o' || tile == 'X') {
                irr::scene::IMeshSceneNode *cube;
                if (tile == '+') {
                    cube = _manager->addCubeSceneNode(10.f, _scenes["map"], id, irr::core::vector3df(x * 10.0f, y * 10.0f, 0.0f));
                    _map.addSoft(std::make_pair(std::make_pair(x, y), cube));
                    cube->setMaterialTexture(0,
                        _driver->getTexture("media/menu_old.jpg"));
                    cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                }
                else if (tile == 'o'){
                    cube = _manager->addMeshSceneNode(
                        _manager->getMesh("media/brick.obj"), 0, -1,
                        irr::core::vector3df(x * 10.0f, y * 10.0f - 5.f, 0.0f),
                        {0, 0, 0}, {0.067, 0.067, 0.067});
                    _map.addHard(std::make_pair(std::make_pair(x, y), cube));
                    cube->setMaterialTexture(0,
                        _driver->getTexture("media/brick.png"));
                    cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);

                }
                irr::scene::ITriangleSelector *selector = _manager->createTriangleSelectorFromBoundingBox(cube);
                cube->setTriangleSelector(selector);
                _meta->addTriangleSelector(selector);
                selector->drop();
            }
        }
}

void Board::addWall(int x, int y)
{
    irr::scene::IMeshSceneNode *cube = _manager->addCubeSceneNode(10.f, 0, -1, irr::core::vector3df(x * 10.f, y * 10.f, 0.0f));

    cube->setVisible(false);
    irr::scene::ITriangleSelector *selector = _manager->createTriangleSelectorFromBoundingBox(cube);
    cube->setTriangleSelector(selector);
    _meta->addTriangleSelector(selector);
    selector->drop();
    _map.addHard(std::make_pair(std::make_pair(-1, y), cube));
}

void Board::createPlayers()
{
    _players.push_back(
        new Player(0, _device, "media/character.x", _map.getPlayer(0), true,
            _meta, _AudioManager));
    if (*_multiplayer)
        _players.push_back(
            new Player(1, _device, "media/character.x", _map.getPlayer(1), true,
                _meta, _AudioManager));
    else
        _players.push_back(
            new Ai(1, _device, "media/character.x", _map.getPlayer(1), Ai::EASY,
                Ai::STANDARD, _meta, _AudioManager, this->_map));
    _players.push_back(
        new Ai(2, _device, "media/character.x", _map.getPlayer(2), Ai::EASY,
            Ai::STANDARD, _meta, _AudioManager, this->_map));
    _players.push_back(
        new Ai(3, _device, "media/character.x", _map.getPlayer(3), Ai::EASY,
            Ai::STANDARD, _meta, _AudioManager, this->_map));
    _players[0]->setTexture("media/white_bomberman_texture.png");
    _players[1]->setTexture("media/black_bomberman_texture.png");
    _players[2]->setTexture("media/red_bomberman_texture.png");
    _players[3]->setTexture("media/gold_bomberman_texture.png");
    for (auto player : _players) {
        player->getMesh()->setFrameLoop(0, 46);
        if (player->getPos().Z == 100)
            player->setAlive(false);
        irr::scene::ITriangleSelector *selector = _manager->createTriangleSelectorFromBoundingBox(player->getMesh());
        _meta->addTriangleSelector(selector);
        selector->drop();
    }
    _event.setP1(_players[0]);
    if (*_multiplayer) {
        std::cout << "Game is multiplayer, setting P2" << std::endl;
        _event.setP2(_players[1]);
    }
}

void Board::initButtons(std::initializer_list<struct ButtonProperties> buttons)
{
    for (const auto &button : buttons) {
        std::string mapKey = button.mapKey;
        std::cout << "Setting up button of key: '" << mapKey << "'"
                  << std::endl;
        irr::video::ITexture *image = _driver->getTexture(
                button.texturePath.c_str());
        irr::core::rect<irr::s32> rect = {static_cast<int>(button.pos.X),
                                          static_cast<int>(button.pos.Y),
                                          static_cast<int>(button.pos.X + image->getSize().Width),
                                          static_cast<int>(button.pos.Y + image->getSize().Height)};
        _buttons[mapKey].button = _gui->addButton(rect, button.parent,
                                                  button.id);
        _buttons[mapKey].button->setImage(image);
        if (!button.pressedTexturePath.empty())
            _buttons[mapKey].button->setPressedImage(
                    _driver->getTexture(button.pressedTexturePath.c_str()));
        _buttons[mapKey].button->setDrawBorder(false);
        _buttons[mapKey].button->setUseAlphaChannel(true);
        _buttons[mapKey].rectangle = rect;
        _buttons[mapKey].hoverAlpha = 0;
        _buttons[mapKey].hoverWidth = 0;
        if (!button.hoverTexturePath.empty())
            _buttons[mapKey].hoverTexture = _driver->getTexture(
                    button.hoverTexturePath.c_str());
    }
}

void Board::update()
{
	static irr::u32 lastTime = 500;
	bool runAi = false;
	bool timerIa = false;
	bool timerHoldIa = false;


	if (_device->getTimer()->getTime() - lastTime >= 100) {
		timerHoldIa = true;

	}
	if (_device->getTimer()->getTime() - lastTime >= 200) {
		timerIa = true;
		lastTime = _device->getTimer()->getTime();

	}

		if (_event.isPause()) {
        return;
    }
		int i = -1;
	for (auto player : _players) {
		i++;
		if (player->isAlive()) {
			if (!player->isHuman()) {
				if (timerIa) {
					runAi = true;
			}
				if (timerHoldIa) {
					static_cast<Ai *>(player)->run(
						this->_bombs, runAi);
				}

			}
			player->update(_bombs, _powerups);
		}
	}
    for (unsigned int i = 0; i < _bombs.size(); i++) {
        deleteBombIfItHasExploded(i);
        for (auto bomb : _bombs) {
            if (bomb->hasExploded()) {
                std::map<std::string, Beam> beams = bomb->getBeams();
                for (auto it = beams.begin(); it != beams.end();) {
                    killPlayerIfItsDead(it);
                    auto hards = _map.getHards();
                    auto softs = _map.getSofts();
                    bool found = false;
                    for (auto hard : hards)
                        if (!found &&
                            it->second.sphere->getTransformedBoundingBox().intersectsWithBox(hard.second->getTransformedBoundingBox())) {
                            std::map<std::string, Beam>::iterator prev = it++;
                            bomb->eraseBeam(prev);
                            found = true;
                            it->second.hit = true;
                        }
                    if (!found)
                        for (auto soft : softs)
                            if (!found && soft.second->isVisible() &&
                                it->second.sphere->getTransformedBoundingBox().intersectsWithBox(soft.second->getTransformedBoundingBox())) {
                                _meta->removeTriangleSelector(soft.second->getTriangleSelector());
                                soft.second->setVisible(false);
                                _map.setTile(soft.second->getPosition().X / 10.f, soft.second->getPosition().Y / 10.f, ' ');


                                std::map<std::string, Beam>::iterator prev = it++;
                                bomb->eraseBeam(prev);
                                found = true;
                                it->second.hit = true;
                            }
                    if (!found)
                        it++;
                }
            }
        }
    }
    checkIfAllPlayersAreDead();
    checkIfCameraMustShake();
    checkPowerupSpawn();
    if (_endingTransition.getCurrentFrame() >= 16 && _playEndingTransition) {
        _activTab = (_isWon ? "win" : "fail");
    }
}

void Board::checkPowerupSpawn()
{
    if (_timer->getTime() >= _lastPowerup + 3000) {
        _lastPowerup = _timer->getTime();
        int x, y;
        bool found = false;
        while (!found) {
            x = rand() % _map.cols();
            y = rand() % _map.rows();
            if (_map.cellIsFree(x, y)) {
                found = true;
            }
            for (auto powerup : _powerups) {
                if (powerup->getPos() == irr::core::vector3df(x * 10.f, y *10.f, 0.f))
                    continue;
            }
        }
        int type = rand() % 4;
        std::vector<std::string> textures = {"media/bag.obj", "media/boots.obj",
            "media/ghost.obj", "media/ghost.obj"};
        std::vector<irr::core::vector3df> rots = {{-90.f, 0.f, 0.f}, {-90.f, 0.f, 0.f}, {-180.f, 0.f, 0.f}, {-180.f, 0.f, 0.f}};
        std::vector<irr::f32> scales = {10.f, 10.f, 1.f, 1.f};
        _powerups.push_back(new Powerup(_device, _meta, _audio, Powerup::Type(type), static_cast<irr::io::path>(textures[type].c_str()), {x * 10.f, y * 10.f, 0.f}, rots[type], scales[type]));
    }
    std::vector<std::vector<Powerup *>::iterator> its;
    for (auto powerup = _powerups.begin() ; powerup != _powerups.end() ; powerup++) {
        if (!(*powerup)->update()) {
            its.push_back(powerup);
        }
    }
    for (auto it : its) {
        delete *it;
        _powerups.erase(it);
    }
}

void Board::checkIfCameraMustShake()
{
    if (!_bombs.empty()) {
        for (const auto &bomb: _bombs) {
            if (bomb->hasExploded()) {
                auto camPos = _device->getSceneManager()->getActiveCamera()->getPosition();
                camPos.X += static_cast<float>(random() % 3 + (-1)) / 2;
                camPos.Y += static_cast<float>(random() % 3 + (-1)) / 2;
                _device->getSceneManager()->getActiveCamera()->setPosition(camPos);
            }
        }
    } else {
        _device->getSceneManager()->getActiveCamera()->setPosition(irr::core::vector3df(_map.cols() / 2 * 10, _map.rows() / 2 * 10, -100.0f));
    }
}

void Board::deleteBombIfItHasExploded(int position)
{
    if (!_bombs.at(position)->update()) {
        delete _bombs[position];
        _bombs.erase(_bombs.begin() + (position * 8));
    }
}

void Board::killPlayerIfItsDead(std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, Beam>> it)
{
    for (auto player : _players) {
        if (it->second.sphere->getTransformedBoundingBox().intersectsWithBox(
                player->getMesh()->getTransformedBoundingBox())) {
            player->setAlive(false);
            player->getMesh()->setVisible(false);
            _meta->removeTriangleSelector(player->getMesh()->getTriangleSelector());
            irr::core::vector3df pos = _map.getPlayer(player->getId());
            _map.setTile(pos.X / 10, pos.Y / 10, ' ');
        }
    }
}

void Board::checkIfAllPlayersAreDead()
{
    int cntHuman = 0;
    int cIa = 0;
    for (auto player : _players) {
        if (player->isAlive()) {
            if (player->isHuman())
                cntHuman++;
            else
                cIa++;
        }
    }
    if (!cIa || !cntHuman) {
        for (auto bomb : _bombs)
            delete bomb;
        _bombs.clear();
        _playEndingTransition = true;
        if (cntHuman) {
            _isWon = true;
        }
    }
}

void Board::drawButtonsHover()
{
    unsigned int fadeSpeed = 50;
    unsigned int uncoverSpeed = 35;
    for (auto &button: _buttons) {
        auto btn = &button.second;
        if (btn->button->getAbsolutePosition().isPointInside(
                {static_cast<int>(_event.MouseState.position.X),
                 static_cast<int>(_event.MouseState.position.Y)})) {
            btn->hoverAlpha += fadeSpeed;
            if (btn->hoverAlpha > 255)
                btn->hoverAlpha = 255;
            btn->hoverWidth += uncoverSpeed;
            if (btn->hoverTexture)
                if (btn->hoverWidth > btn->hoverTexture->getSize().Width)
                    btn->hoverWidth = btn->hoverTexture->getSize().Width;
        } else {
            btn->hoverAlpha -= fadeSpeed;
            if (btn->hoverAlpha > 255)
                btn->hoverAlpha = 0;
            btn->hoverWidth -= uncoverSpeed;
            if (btn->hoverTexture)
                if (btn->hoverWidth > btn->hoverTexture->getSize().Width)
                    btn->hoverWidth = 0;
        }
        if (btn->hoverTexture)
            _driver->draw2DImage(btn->hoverTexture,
                                 irr::core::position2d<irr::s32>(
                                         btn->button->getAbsolutePosition().UpperLeftCorner),
                                 irr::core::rect<irr::s32>(0, 0, btn->hoverTexture->getSize().Width,
                                                           btn->hoverTexture->getSize().Height), 0,
                                 irr::video::SColor(btn->hoverAlpha, 255, 255, 255), true);
    }
}

void Board::draw()
{
    if (_event.isPause()) {
        if (!_event.getQuittingChoice().empty()) {
            _buttons["resume"].button->setRelativePosition({2000, _buttons["resume"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["save"].button->setRelativePosition({2000, _buttons["save"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitMenu"].button->setRelativePosition({2000, _buttons["quitMenu"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitDesktop"].button->setRelativePosition({2000, _buttons["quitDesktop"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitConfirm"].button->setRelativePosition({1920 / 2 + 10, _buttons["quitConfirm"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitCancel"].button->setRelativePosition({1920 / 2 - 387 - 10, _buttons["quitCancel"].button->getAbsolutePosition().UpperLeftCorner.Y});
        } else {
            _buttons["resume"].button->setRelativePosition({1920 / 2 - 381 / 2, _buttons["resume"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["save"].button->setRelativePosition({1920 / 2 - 381 / 2, _buttons["save"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitMenu"].button->setRelativePosition({1920 / 2 - 381 / 2, _buttons["quitMenu"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitDesktop"].button->setRelativePosition({1920 / 2 - 381 / 2, _buttons["quitDesktop"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitConfirm"].button->setRelativePosition({2000, _buttons["quitConfirm"].button->getAbsolutePosition().UpperLeftCorner.Y});
            _buttons["quitCancel"].button->setRelativePosition({2000, _buttons["quitCancel"].button->getAbsolutePosition().UpperLeftCorner.Y});
        }
        _gui->drawAll();
        drawButtonsHover();
        if (_event.getQuittingChoice() == "menu") {
            _driver->draw2DImage(_textures["textQuitToMenu"], {static_cast<int>(1920 / 2 - _textures["textQuitToMenu"]->getSize().Width / 2), 200},
                                 irr::core::rect<irr::s32>(0, 0,
                                                           _textures["textQuitToMenu"]->getSize().Width,
                                                           _textures["textQuitToMenu"]->getSize().Height), 0,
                                 irr::video::SColor(255, 255, 255, 255), true);
        } else if (_event.getQuittingChoice() == "desktop") {
            _driver->draw2DImage(_textures["textQuitToDesktop"], {static_cast<int>(1920 / 2 - _textures["textQuitToDesktop"]->getSize().Width / 2), 200},
                    irr::core::rect<irr::s32>(0, 0,
                                              _textures["textQuitToDesktop"]->getSize().Width,
                                              _textures["textQuitToDesktop"]->getSize().Height), 0,
                    irr::video::SColor(255, 255, 255, 255), true);
        }
    }
    _transition.play();
    if (_playEndingTransition) {
        _endingTransition.play();
    }
}