
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "moveable.h"
#include <vector>

Moveable::Moveable(const std::vector<float> &position, const std::vector<float> &size)
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
}


