
#include "barricadem.h"
#include "moveable.h"

#include <vector>

BarricadeM::BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour):
    Moveable(position, size)
{
    if(position.size()==2)
    {
        position_ = position;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }

    if(size.size()==2)
    {
        size_ = size;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }

    if(colour.size()==3)
    {
        _colour = colour;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }
    _rectangleG.setPosition(sf::Vector2f(position[0], position[1]));
    _rectangleG.setSize(sf::Vector2f(size[0], size[1]));
    _rectangleG.setFillColor(sf::Color(colour[0], colour[1], colour[2]));

}

void BarricadeM::setColour(const std::vector<float> &colour)
{
    _colour = colour;
    _rectangleG.setFillColor(sf::Color(_colour[0], _colour[1], _colour[2]));
}

bool BarricadeM::checkBounds(){return true;};

sf::RectangleShape& BarricadeM::getRectangleShape() {
    return _rectangleG;
}
