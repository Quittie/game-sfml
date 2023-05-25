
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
    _rectangleG.setPosition(sf::Vector2f(_position[0], _position[1]));
    _rectangleG.setSize(sf::Vector2f(_size[0], _size[1]));

}

void BarricadeM::setColour(const std::vector<float> &colour)
{
    _colour = colour;
}

void BarricadeM::setColBar()
{
    _rectangleG.setFillColor(sf::Color::Green);
}


bool BarricadeM::checkBounds(){return true;};
