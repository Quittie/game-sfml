#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "moveable.h"
#include <vector>

Moveable::Moveable(const std::vector<float> &position, const std::vector<float> &size)
{
    if(position.size()==3)
    {
        position_ = position;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }

    if(size.size()==3)
    {
        size_ = size;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }
}


