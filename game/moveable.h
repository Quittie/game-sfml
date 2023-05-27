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
    Moveable(const std::vector<float> &position, const std::vector<float> &size);
    virtual bool checkBounds() = 0;
protected:
    std::vector<float> _position;
    std::vector<float> _size;
    sf::FloatRect _bounds;
};

#endif // MOVEABLE_H
