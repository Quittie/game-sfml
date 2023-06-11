#ifndef GAME_BALL_H
#define GAME_BALL_H


#include "moveable.h"

class Ball : public Moveable{
public:
    Ball(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed);
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget* target);
    void reset();
    const sf::CircleShape &getShape() const;
    void kick(float velocityX, float velocityY);

    const sf::Vector2f &getBallVelocity() const;


private:
    sf::CircleShape _shape;
    sf::Vector2f _ballVelocity;
    void loadTexture(const std::string& source);
    void updateKick();
    void updateWindowBoundsCollision(sf::RenderTarget *target);
};



#endif //GAME_BALL_H
