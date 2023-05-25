
#include "barricadem.h"
#include "moveable.h"

#include <vector>

BarricadeM::BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour):
    Moveable(position, size)
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

    if(colour.size()==3)
    {
        _colour = colour;
    }
    else
    {
        std::cout << "Enter proper values" << std::endl;
    }
}

