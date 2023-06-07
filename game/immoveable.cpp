
#include "immoveable.h"

#include <iostream>
#include <vector>

Immoveable::Immoveable(const std::vector<float> &position, const std::vector<float> &scale)
{
    if(position.size()==2)
    {
        _position = position;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }

    if(scale.size()==2)
    {
        _scale = scale;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }


//    if(size.size()==3)
//    {
//        size_ = size;
//    }
//    else
//    {
//        std::cout << "Enter proper values" << std::endl;
//    }
}

sf::Sprite Immoveable::getSprite()
{
    return _sprite;
}

