
#include "hud.h"

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


hud::hud(const std::vector<float> &position, const std::vector<float> &scale, const std::string &source)
{
    _position = position;
    _scale = scale;

    if(!_texture.loadFromFile(source))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    else
    {
        std::cout << "Added" << std::endl;

        _hud_object.setTexture(_texture);
        _hud_object.setScale(_scale[0], _scale[1]);
        _hud_object.setPosition(_position[0], _position[1]);
    }
}

sf::Sprite hud::getHUD()
{
    return _hud_object;
}
