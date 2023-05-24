
#ifndef HUD_H
#define HUD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>




class hud : public sf::Sprite
{
public:
    hud(const std::vector<int> &position, const std::vector<int> &size, const sf::Texture &texture);
protected:
    std::vector<int> _position;
    std::vector<int> _size;
    sf::Texture _texture;
};

#endif // HUD_H
