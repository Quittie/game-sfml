
#ifndef IMMOVEABLE_H
#define IMMOVEABLE_H

#include <iostream>
#include <vector>



class Immoveable
{
protected:
    Immoveable(const std::vector<float> &position, const std::vector<float> &size);
    std::vector<float> position_;
    std::vector<float> size_;
};

#endif // IMMOVEABLE_H
