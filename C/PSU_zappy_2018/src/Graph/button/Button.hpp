/*
** EPITECH PROJECT, 2018
** Graph
** File description:
** Button.hpp
*/

#ifndef GRAPH_BUTTON_HPP
#define GRAPH_BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button: public sf::Drawable {
public:
    Button(std::string texturePath, std::string hoveredTexturePath, std::string clickedTexturePath);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    ~Button();
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Texture _hoveredTexture;
    sf::Texture _clickedTexture;
private:
};

#endif //GRAPH_BUTTON_HPP
