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
    Moveable(const std::vector<float> &position, const std::vector<float> &size, float speed);
    void speedUp();
protected:
    sf::Texture _texture;
    std::vector<float> _startingPosition;
    std::vector<float> _position;
    std::vector<float> _size;
    float _speed;
};

#endif // MOVEABLE_H
