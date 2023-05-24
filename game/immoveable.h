
#ifndef IMMOVEABLE_H
#define IMMOVEABLE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>



class Immoveable : public sf::Sprite
{
protected:
    Immoveable(const std::vector<float> &position, const std::vector<float> &size);
    std::vector<float> position_;
    std::vector<float> size_;
};

#endif // IMMOVEABLE_H
