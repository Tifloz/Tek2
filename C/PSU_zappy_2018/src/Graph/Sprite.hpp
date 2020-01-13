/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Sprite.hpp
*/

#ifndef GRAPH_SPRITE_HPP
#define GRAPH_SPRITE_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Sprite: public sf::Drawable {
public:
    Sprite(sf::RenderWindow *window, std::string path, int divX, int divY);
    Sprite(const Sprite &other);
    Sprite();
    ~Sprite();


    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Sprite getSprite() const;
    void setNextFrame();
    int addAnimation(int start, int end, int speed, bool loop, bool reverse);
    void setAnimation(int num);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;
    int getCurrentAnimation() const;
    int getCurrentFrame() const;
    void setAnimationSpeed(int num, int newspeed);
    int getAnimationSpeed(int num);
    int getAnimationStart(int num);
    void removeAnimation(int num);
    void clearAnimations();
    int getAnimationEnd(int num);
    void setScale(sf::Vector2f scale);
    sf::Vector2f getScale() const;
    sf::Texture getTexture() const;

private:
    struct Animation
    {
        int start;
        int end;
        int speed;
        bool loop;
        bool reverse;
    };
    sf::RenderWindow *_window;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Clock _clock;
    std::vector<sf::Rect<int>> _frame;
    int _currentFrame;
    int _currentAnim;

    sf::Rect<int> _position;

    std::vector<Animation> _animations;

};

#endif //GRAPH_SPRITE_HPP
