
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "moveable.h"
#include <vector>

Moveable::Moveable(const std::vector<float> &position, const std::vector<float> &size, float speed) {
    _startingPosition = position;
    _position = position;
    _size = size;
    _speed = speed;

}

