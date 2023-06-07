
#ifndef IMMOVEABLE_H
#define IMMOVEABLE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>



class Immoveable : public sf::Sprite
{
public:
    Immoveable(const std::vector<float> &position, const std::vector<float> &scale);
    sf::Sprite getSprite();
protected:
    sf::Texture _texture;
    sf::Sprite _sprite;;
    std::vector<float> _position  = {0,0};
    std::vector<float> _scale  = {1,1};
};

#endif // IMMOVEABLE_H
