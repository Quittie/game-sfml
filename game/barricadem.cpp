#include "barricadem.h"
#include "moveable.h"
#include "game.h"

#include <vector>

BarricadeM::BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour, float speed):
    Moveable(position, size, speed)
{
    if(position.size()==2)
    {
        _position = position;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }

    if(size.size()==2)
    {
        _size = size;
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
    this->_rectangleG = new sf::RectangleShape(sf::Vector2f(size[0], size[1]));
    this->_rectangleG->setPosition(sf::Vector2f(position[0], position[1]));
    this->_rectangleG->setFillColor(sf::Color(colour[0], colour[1], colour[2]));


    _speed=speed/60;

}

void BarricadeM::setColour(const std::vector<float> &colour)
{
    _colour = colour;
    this->_rectangleG->setFillColor(sf::Color(_colour[0], _colour[1], _colour[2]));
}




sf::RectangleShape* BarricadeM::getRectangleShape() {
    return this->_rectangleG;
}

void BarricadeM::moveBarricade(Game *game)
{
    _position[1] += _speed;
    this->_rectangleG->setPosition(sf::Vector2f(_position[0], _position[1]));
    _posY = _rectangleG->getPosition().y;
    _posX = _rectangleG->getPosition().x;

    if(_posY <= 0)
    {
        _speed *= -1;
    }

    if(_posY >= game->getwindow()->getSize().y - this->_rectangleG->getSize().y )
    {
        _speed *= -1;
    }


}
//    if(this->_rectangleG->getPosition()
