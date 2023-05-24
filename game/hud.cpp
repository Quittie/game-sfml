
#include "hud.h"

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


hud::hud(const std::vector<int> &position, const std::vector<int> &size, const sf::Texture &texture):
    _position(position), _size(size), _texture(texture){}

