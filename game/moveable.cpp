
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "moveable.h"
#include <vector>

Moveable::Moveable(const std::vector<float> &position, const std::vector<float> &size, float speed) { //class constructor
    _startingPosition = position;
    _position = position;
    _size = size;
    _speed = speed;

}

void Moveable::speedUp() //increases the speed of moveable objects
{
    _speed++;
}

