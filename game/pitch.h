
#ifndef PITCH_H
#define PITCH_H

#include <vector>
#include "immoveable.h"
#include "game.h"


class Pitch : public Immoveable
{
public:

    Pitch(const std::string &source, const std::vector<float> &position, const std::vector<float> &scale);
    void setRect(Game &game);
    sf::Sprite getSprite();
private:

    sf::Sprite _pitch;
//    void makeSprite();
};

#endif // PITCH_H
