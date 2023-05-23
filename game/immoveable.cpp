
#include "immoveable.h"

immoveable::immoveable(const std::vector<int> &position, const std::vector<int> &size)
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

