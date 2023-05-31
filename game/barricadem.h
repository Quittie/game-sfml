

#ifndef BARRICADEM_H
#define BARRICADEM_H

#include <vector>
#include "moveable.h"

class Game;

class BarricadeM : public Moveable
{
public:
    BarricadeM(const std::vector<float> &position, const std::vector<float> &size, const std::vector<float> &colour, float speed);
    void displayColour();
    void moveBarricade(Game* game);
    void setColour(const std::vector<float> &color);
    void setColBar();
//    virtual bool checkBounds();
    sf::RectangleShape* getRectangleShape();
protected:
    sf::RectangleShape *_rectangleG;
    std::vector<float> _colour;
    float _speed;
    float _posX = 0.0;
    float _posY = 0.0;
};

#endif // BARRICADEM_H
