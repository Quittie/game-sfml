
#include "pitch.h"
#include <vector>
#include <string>
#include <iostream>

Pitch::Pitch(const std::string &source, const std::vector<float> &position, const std::vector<float> &scale):Immoveable(position, scale)
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
        _texture.setRepeated(true);
        _pitch.setTexture(_texture);
        _pitch.setScale(_scale[0], _scale[1]);
    }

}


void Pitch::setRect(Game &game)
{
    _pitch.setTextureRect(sf::IntRect(0, 0, game.getwindow()->getSize().x, game.getwindow()->getSize().y));
}

sf::Sprite Pitch::getSprite()
{
    return _pitch;
}
