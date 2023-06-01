
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
    Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source);
    sf::Sprite  getSprite();
    sf::Texture getTexture();
    void move();
//    virtual bool checkBounds();
private:
    std::string _source;
    sf::Texture _texture;
    sf::Sprite _player;


};

#endif // PLAYER_H
