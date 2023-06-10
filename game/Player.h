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
    Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed);
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
    const Sprite &getSprite() const;

    void reset();

    void updatePosition(float x, float y);

private:
    sf::Sprite _sprite;

private:
    void loadTexture(const std::string& source);
    void loadSprite();
    void updateInput();
    void updateWindowBoundsCollision(sf::RenderTarget *target);
};

#endif // PLAYER_H
