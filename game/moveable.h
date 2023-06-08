#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <string>
#include <vector>
#include <iostream>


class Moveable : public sf::Sprite
{
public:
    Moveable(const std::vector<float> &position, const std::vector<float> &size, int velocity);
    sf::Sprite getSprite();
    std::vector<float> getSize();


//    virtual bool checkBounds();
protected:

    sf::Texture _texture;
    sf::Sprite _sprite;
    std::vector<float> _position;
    std::vector<float> _size;
    sf::FloatRect _bounds;
    int _velocity;
};

#endif // MOVEABLE_H
