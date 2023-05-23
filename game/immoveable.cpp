
#include "immoveable.h"

#include <iostream>
#include <vector>

Immoveable::Immoveable(const std::vector<float> &position, const std::vector<float> &size)
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

