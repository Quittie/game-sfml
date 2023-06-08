
#ifndef PLAYER_H
#define PLAYER_H

#include "moveable.h"


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>


class Player : public Moveable
{
public:
    Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, int velocity);
    sf::Sprite getSprite();
    void move();



//    virtual bool checkBounds();
private:
    std::string _source;
    sf::Event ev;

};

#endif // PLAYER_H
