
#ifndef BARRICADEM_H
#define BARRICADEM_H

#include <vector>

#include "moveable.h"


class BarricadeM : public Moveable
{
public:
    BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour);
    void displayColour();
    void moveBarricade(sf::Window window);
    void setColour(const std::vector<float> &color);
    void setColBar();
    virtual bool checkBounds();
    sf::RectangleShape& getRectangleShape();
protected:
    sf::RectangleShape _rectangleG;
    std::vector<float> _colour;
};

#endif // BARRICADEM_H
