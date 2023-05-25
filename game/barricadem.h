
#ifndef BARRICADEM_H
#define BARRICADEM_H

#include <vector>

#include "moveable.h"


class BarricadeM : public Moveable
{
public:
    BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour);
    void displayColour();
    void moveBarricade();
    void setColour(const std::vector<float> &color);
    virtual bool checkBounds();
protected:
    std::vector<float> _colour;

};

#endif // BARRICADEM_H
