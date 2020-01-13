/*
** EPITECH PROJECT, 2019
** Graph
** File description:
** Created by Denis Demouveau,
*/

#include <sstream>
#include "Error.hpp"
#include "Game.hpp"

Game::Game(sf::RenderWindow *window, std::string &activeTab, Socket &server) :
Scene(window, activeTab), _server(server)
{
}

#include <iostream>

std::vector<std::string> Game::explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}


bool Game::init()
{
    std::string infos;
    std::string tmp;
    if (!(_server << "GRAPHIC"))
        throw ZappyError("initial message error");
    _server >> tmp;
    if (tmp.find("start init") == std::string::npos) {
        if (tmp == "Graphic already connected\n")
            throw ZappyError("too many graphical interfaces connected");
        throw ZappyError("connection initialising error");
    }
    bool isBreak = false;
    while (infos.find("end init") == std::string::npos) {
        std::vector<std::string> lines = explode(tmp, '\n');
        for (const auto &string: lines) {
            if (string == "YOU ARE GRAPHIC") {
                isBreak = true;
                break;
            }
            infos += string + "\n";
        }
        if (isBreak)
            break;
        _server >> tmp;
    }
    infos += tmp;


    std::stringstream stream(infos);
    std::string line;

    std::getline(stream, line);
    std::getline(stream, line);
    std::getline(stream, line);
    tna(line);
    std::getline(stream, line);
    while (line.substr(0, 4) == "jpp ") {
        pp(line);
        std::getline(stream, line);
    }
   if (!msz(line))
       return false;
   std::getline(stream, line);
   while (line.substr(0, 4) == "bct ") {
        bct(line);
        std::getline(stream, line);
   }
   _orig = _window->getView();
    _sprites["transition"] = new Sprite(_window, "assets/transition.png", 6, 7);
    _sprites["transition"]->addAnimation(16, 41, 30, false, false);
    _sprites["transition"]->setAnimation(0);
    _sprites["transition"]->setScale({1.5, 1.7});

    for (int x = 0; x < _map.getWidth(); x++) {
        for (int y = 0; y < _map.getHeight(); y++) {
            Sprite *tile = new Sprite(_window, "assets/tile.png", 1, 1);
            tile->setPosition({static_cast<float>(x * 64), static_cast<float>(y * 64)});
            _tiles.push_back(tile);
        }
    }
    for (const auto &team: _teams) {
        for (auto player: team->getPlayers()) {
            player->_sprite = new Sprite(_window, "assets/character.png", 3, 1);
            player->_sprite->setPosition({static_cast<float>(player->getX() * 64), static_cast<float>(player->getY() * 64)});
        }
    }

    for (unsigned int y = 0; y < _map.getTiles().size(); y++) {
        for (unsigned int x = 0; x < _map.getTiles()[y].size(); x++) {
            for (int i = 0; i < _map.getTiles()[x][y].food; i++) {
                Sprite *food = new Sprite(_window, "assets/food.png", 1, 1);
                food->setPosition({
                    static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                    static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                });
                _food.push_back(food);
            }
            for (int i = 0; i < _map.getTiles()[x][y].thystame; i++) {
                Sprite *thystame = new Sprite(_window, "assets/thystame.png", 1, 1);
                thystame->setPosition({
                                          static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                          static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                  });
                _thystame.push_back(thystame);
            }
            for (int i = 0; i < _map.getTiles()[x][y].phiras; i++) {
                Sprite *phiras = new Sprite(_window, "assets/phiras.png", 1, 1);
                phiras->setPosition({
                                              static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                              static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                      });
                _phiras.push_back(phiras);
            }
            for (int i = 0; i < _map.getTiles()[x][y].mendiane; i++) {
                Sprite *mendiane = new Sprite(_window, "assets/mendiane.png", 1, 1);
                mendiane->setPosition({
                                            static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                            static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                    });
                _mendiane.push_back(mendiane);
            }
            for (int i = 0; i < _map.getTiles()[x][y].sibur; i++) {
                Sprite *sibur = new Sprite(_window, "assets/sibur.png", 1, 1);
                sibur->setPosition({
                                            static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                            static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                    });
                _sibur.push_back(sibur);
            }
            for (int i = 0; i < _map.getTiles()[x][y].deraumere; i++) {
                Sprite *deraumere = new Sprite(_window, "assets/deraumere.png", 1, 1);
                deraumere->setPosition({
                                            static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                            static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                    });
                _deraumere.push_back(deraumere);
            }
            for (int i = 0; i < _map.getTiles()[x][y].linemate; i++) {
                Sprite *linemate = new Sprite(_window, "assets/linemate.png", 1, 1);
                linemate->setPosition({
                                            static_cast<float>(rand()%(((x + 1) * 64 - 4) - x * 64 + 1) + x * 64),
                                            static_cast<float>(rand()%(((y + 1) * 64 - 4) - y * 64 + 1) + y * 64)
                                    });
                _linemate.push_back(linemate);
            }
        }
    }

    _selector = new Sprite(_window, "assets/selector.png", 1, 1);
    _selector2 = new Sprite(_window, "assets/selector2.png", 1, 1);

    _peekMenu = new Sprite(_window, "assets/peek_menu.png", 1, 1);
    _peekMenu->setPosition({1200, 0});

    _sprites["peekMenuRightArrow"] = new Sprite(_window, "assets/right_arrow.png", 1, 1);

    _sprites["linematePrev"] = new Sprite(_window, "assets/linemate_preview.png", 1, 1);
    _sprites["linematePrev"]->setScale({0.1, 0.1});
    _sprites["deraumerePrev"] = new Sprite(_window, "assets/deraumere_preview.png", 1, 1);
    _sprites["deraumerePrev"]->setScale({0.1, 0.1});
    _sprites["siburPrev"] = new Sprite(_window, "assets/sibur_preview.png", 1, 1);
    _sprites["siburPrev"]->setScale({0.1, 0.1});
    _sprites["mendianePrev"] = new Sprite(_window, "assets/mendiane_preview.png", 1, 1);
    _sprites["mendianePrev"]->setScale({0.1, 0.1});
    _sprites["phirasPrev"] = new Sprite(_window, "assets/phiras_preview.png", 1, 1);
    _sprites["phirasPrev"]->setScale({0.1, 0.1});
    _sprites["thystamePrev"] = new Sprite(_window, "assets/thystame_preview.png", 1, 1);
    _sprites["thystamePrev"]->setScale({0.1, 0.1});

    _sprites["background"] = new Sprite(_window, "assets/game_background.png", 1, 1);

    _sprites["keys"] = new Sprite(_window, "assets/keys.png", 1, 1);
    _sprites["keys"]->setScale({2, 2});
    _sprites["keys"]->setPosition({10, 10});

    if (!_font.loadFromFile("assets/font.ttf"))
        throw ZappyError("The font 'assets/font.ttf did not load properly, aborting...'");

    _texts["title"] = sf::Text("Tile Ressources", _font, 30);
    _texts["food"] = sf::Text("Food: ", _font, 30);
    _texts["linemate"] = sf::Text("Linemate: ", _font, 30);
    _texts["deraumere"] = sf::Text("Deraumere: ", _font, 30);
    _texts["sibur"] = sf::Text("Sibur: ", _font, 30);
    _texts["mendiane"] = sf::Text("Mendiane: ", _font, 30);
    _texts["phiras"] = sf::Text("Phiras: ", _font, 30);
    _texts["thystame"] = sf::Text("Thystame: ", _font, 30);
    _texts["playersOnTile"] = sf::Text("Players on this tile: ", _font, 30);

    _view.setCenter((_map.getWidth() / 2) * 64, (_map.getHeight() / 2) *64);
    _loaded = true;
    return true;
}

void Game::update()
{
    fd_set rd;
    struct timeval tm = {0, 0};
    std::string line;

    FD_ZERO(&rd);
    FD_SET(_server.getFd(), &rd);
    if (select(_server.getFd() + 1, &rd, nullptr, nullptr, &tm) == -1)
        throw ZappyError("select error");
    if (FD_ISSET(_server.getFd(), &rd)) {
        _server >> line;
        handleCommand(line);
    }
/*
    for (auto team: _teams) {
        for (auto player: team->getPlayers()) {
            player->_sprite->setNextFrame();
        }
    }*/

    if (_sprites["transition"]->getCurrentFrame() < 41) {
        _sprites["transition"]->setNextFrame();
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(*_window);
    sf::Vector2f mousePosWorld = _window->mapPixelToCoords(mousePos, _view);
    for (const auto &tile: _tiles) {
        if (tile->getSprite().getGlobalBounds().contains({mousePosWorld.x, mousePosWorld.y})) {
            _selector->setPosition(tile->getSprite().getPosition());
        }
    }

    _peekMenu->setPosition({(_peekRessources ? 1200 - _peekMenu->getSprite().getGlobalBounds().width : 1200), 0});

        _texts["title"].setString("Tile Resources");
        _texts["food"].setString("Food: " + std::to_string(selectedTile.food));
        _texts["linemate"].setString("Linemate: " + std::to_string(selectedTile.linemate));
        _texts["deraumere"].setString("Deraumere: " + std::to_string(selectedTile.deraumere));
        _texts["sibur"].setString("Sibur: " + std::to_string(selectedTile.sibur));
        _texts["mendiane"].setString("Mendiane: " + std::to_string(selectedTile.mendiane));
        _texts["phiras"].setString("Phiras: " + std::to_string(selectedTile.phiras));
        _texts["thystame"].setString("Thystame: " + std::to_string(selectedTile.thystame));
        int playersOnTile = 0;
        for (auto team: _teams) {
            for (auto player: team->getPlayers()) {
                if (player->getX() * 64 == _selector->getSprite().getPosition().x && player->getY() * 64 == _selector->getSprite().getPosition().y) {
                    playersOnTile += 1;
                }
            }
        }
        _texts["playersOnTile"].setString("Players: " + (playersOnTile == 0 ? "none" : std::to_string(playersOnTile)));

    _sprites["linematePrev"]->setPosition({_peekMenu->getPosition().x + 10, 200});
    _sprites["deraumerePrev"]->setPosition({_peekMenu->getPosition().x + 10, 250});
    _sprites["siburPrev"]->setPosition({_peekMenu->getPosition().x + 10, 300});
    _sprites["mendianePrev"]->setPosition({_peekMenu->getPosition().x + 10, 350});
    _sprites["phirasPrev"]->setPosition({_peekMenu->getPosition().x + 10, 400});
    _sprites["thystamePrev"]->setPosition({_peekMenu->getPosition().x + 10, 450});

    _texts["title"].setPosition({_peekMenu->getPosition().x + 100, 100});
    _texts["food"].setPosition({_peekMenu->getPosition().x + 100, 150});
    _texts["linemate"].setPosition({_peekMenu->getPosition().x + 100, 200});
    _texts["deraumere"].setPosition({_peekMenu->getPosition().x + 100, 250});
    _texts["sibur"].setPosition({_peekMenu->getPosition().x + 100, 300});
    _texts["mendiane"].setPosition({_peekMenu->getPosition().x + 100, 350});
    _texts["phiras"].setPosition({_peekMenu->getPosition().x + 100, 400});
    _texts["thystame"].setPosition({_peekMenu->getPosition().x + 100, 450});
    _texts["playersOnTile"].setPosition({_peekMenu->getPosition().x + 100, 500});

    _sprites["peekMenuRightArrow"]->setPosition({_peekMenu->getSprite().getGlobalBounds().left + _peekMenu->getSprite().getGlobalBounds().width - _sprites["peekMenuRightArrow"]->getSprite().getGlobalBounds().width - 20, 20});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        _view.move({-2, 0});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _view.move({0, 2});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _view.move({2, 0});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        _view.move({0, -2});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _view.zoom(1.02);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        _view.zoom(0.98);
    }
}

void Game::draw()
{
    _window->draw(*_sprites["background"]);
    _window->setView(_view);
    for (const auto &tile: _tiles) {
        _window->draw(*tile);
    }
    for (const auto &food: _food) {
        _window->draw(*food);
    }
    for (const auto &thystame: _thystame) {
        _window->draw(*thystame);
    }
    for (const auto &phiras: _phiras) {
        _window->draw(*phiras);
    }
    for (const auto &mendiane: _mendiane) {
        _window->draw(*mendiane);
    }
    for (const auto &sibur: _sibur) {
        _window->draw(*sibur);
    }
    for (const auto &deraumere: _deraumere) {
        _window->draw(*deraumere);
    }
    for (const auto &linemate: _linemate) {
        _window->draw(*linemate);
    }
    if (_peekRessources)
        _window->draw(*_selector2);
    _window->draw(*_selector);
    for (auto team: _teams) {
        for (auto player: team->getPlayers()) {
            if (!player->s_init)
                player->initSprite(_window, "assets/character.png", 3, 1);
            player->_sprite->setPosition({
                static_cast<float>(player->getX() * 64 + player->_sprite->getSprite().getGlobalBounds().width / 2),
                static_cast<float>(player->getY() * 64 + player->_sprite->getSprite().getGlobalBounds().height / 2)
            });
            _window->draw(*player->_sprite);
        }
    }
    _window->setView(_orig);
    _window->draw(*_peekMenu);
    _window->draw(*_sprites["peekMenuRightArrow"]);
    _window->draw(*_sprites["linematePrev"]);
    _window->draw(*_sprites["deraumerePrev"]);
    _window->draw(*_sprites["siburPrev"]);
    _window->draw(*_sprites["mendianePrev"]);
    _window->draw(*_sprites["phirasPrev"]);
    _window->draw(*_sprites["thystamePrev"]);
    _window->draw(*_sprites["keys"]);
    for (const auto &text: _texts) {
        _window->draw(text.second);
    }
    if (_sprites["transition"]->getCurrentFrame() < 41) {
        _window->draw(*_sprites["transition"]);
    }
}

void Game::unload()
{
    _loaded = false;
}

void Game::handleCommand(const std::string &line)
{
    size_t pos = 0;
    std::string copy(line);
    std::string token;

    while ((pos = copy.find('\n')) != std::string::npos) {
        token = copy.substr(0, pos);
        std::string head = copy.substr(0, copy.find_first_of(" \n"));

        if (head == "Quit")
            _window->close();
        else if (head == "pdi")
            pdi(token);
        else if (head == "jpp")
            pp(token);
        else if (head == "bct")
            bct(token);

        copy.erase(0, pos + 1);
    }
}

bool Game::msz(const std::string &line)
{
    std::string copy(line);
    int x, y;

    copy.erase(0, copy.find(' ') + 1);
    x = stoi(copy.substr(0, copy.find(' ')));
    copy.erase(0, copy.find(' ') + 1);
    y = stoi(copy.substr(0, copy.find(' ')));
    return _map.init(x, y);
}

bool Game::bct(const std::string &line)
{
    size_t pos = 0;
    std::string copy(line);
    std::string token;
    std::vector<int> infos;

    copy.erase(0, copy.find(' ') + 1);
    while ((pos = copy.find_first_of(" \n")) != std::string::npos) {
        token = copy.substr(0, pos);
        infos.push_back(stoi(copy.substr(0, copy.find_first_of(" \n"))));
        copy.erase(0, pos + 1);
    }

    infos.push_back(stoi(copy));
    _map.setTile(infos[0], infos[1], {infos[2], infos[3], infos[4], infos[5], infos[6], infos[7], infos[8]});
    return true;
}

bool Game::tna(const std::string &line)
{
    size_t pos = 0;
    std::string copy(line);
    std::string token;

    copy.erase(0, copy.find(' ') + 1);
    while ((pos = copy.find(' ')) != std::string::npos) {
        token = copy.substr(0, pos);
        _teams.push_back(new Team(token));
        copy.erase(0, pos + 1);
    }
    return true;
}

bool Game::pp(const std::string &line)
{
    size_t pos = 0;
    std::string copy(line);
    std::string token;
    std::vector<int> infos;

    copy.erase(0, copy.find(' ') + 1);
    while ((pos = copy.find(' ')) != std::string::npos) {
        token = copy.substr(0, pos);
        infos.push_back(stoi(copy.substr(0, copy.find(' '))));
        copy.erase(0, pos + 1);
    }
    for (auto player : _teams[infos[0]]->getPlayers()) {
        if (player->getId() == infos[1]) {
            _teams[infos[0]]->setPlayer(infos);
            return true;
        }
    }
    _teams[infos[0]]->addPlayer(infos);
    return true;
}

bool Game::pdi(const std::string &line)
{
    size_t pos = 0;
    std::string copy(line);
    std::string token;
    std::vector<int> infos;

    copy.erase(0, copy.find(' ') + 1);
    while ((pos = copy.find(' ')) != std::string::npos) {
        token = copy.substr(0, pos);
        infos.push_back(stoi(copy.substr(0, copy.find(' '))));
        copy.erase(0, pos + 1);
    }
    infos[1] = stoi(copy);
    _teams[infos[0]]->removePlayer(infos[1]);
    return true;
}

void Game::handleEvents() {
    while (_window->pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window->close();
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::MouseButtonReleased:
            {
                _window->setView(_view);
                sf::Vector2i mousePos = sf::Mouse::getPosition(*_window);
                sf::Vector2f mousePosWorld = _window->mapPixelToCoords(mousePos, _view);
                if (_sprites["peekMenuRightArrow"]->getSprite().getGlobalBounds().contains({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)})) {
                    _peekRessources = false;
                }
                _window->setView(_orig);
                for (const auto &tile: _tiles) {
                    if (tile->getSprite().getGlobalBounds().contains({mousePosWorld.x, mousePosWorld.y})) {
                        _selector2->setPosition(tile->getPosition());
                        _peekRessources = true;
                         break;
                    }
                }
                Tile tile = _map.getTiles()[_selector2->getSprite().getPosition().x / 64][_selector2->getSprite().getPosition().y / 64];
                selectedTile = tile;
                break;
            }
            default:
                break;
        }
    }
}

