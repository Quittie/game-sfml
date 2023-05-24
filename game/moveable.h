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
protected:
    virtual bool checkBounds();
    std::vector<float> position_;
    std::vector<float> size_;
    sf::FloatRect bounds_;
};

#endif // MOVEABLE_H
