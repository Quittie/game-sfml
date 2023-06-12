
#include <valarray>
#include "Ball.h"

Ball::Ball(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed) : Moveable(position, size, speed) { //contructor of class Ball
    loadTexture(source); //loads texture from provided file
    _shape.setTexture(&_texture); //sets texture for the sprite
    _shape.setPosition(this->_position[0], this->_position[1]); //sets initial position of the ball
    _shape.setRadius(25); //sets ball's radius
    _ballVelocity = sf::Vector2f (0, 0); // sets initial ball velocity
}

void Ball::update(sf::RenderTarget *target) { //is responsible for updating ball's states
    this->updateKick(); //moves ball with given velocity
    this->updateWindowBoundsCollision(target); //verifies collision with window's bounds
}

void Ball::updateKick() {
    _shape.move(_ballVelocity); //moves ball with given velocity

}

void Ball::updateWindowBoundsCollision(sf::RenderTarget *target) { //verifies collision with window's bounds
    sf::FloatRect ballBounds = getShape().getGlobalBounds(); //gets currents bounds of the ball
    if (ballBounds.left <= 0.f || ballBounds.left + ballBounds.width  >= target->getSize().x) { //checks if ball hits edges with respect to x
        //Bounce from the right or left bound of the window
        _ballVelocity.x = -_ballVelocity.x;
    }

    if (ballBounds.top <= 0.f || ballBounds.top + ballBounds.height >= target->getSize().y) { //checks if ball hits edges with respect to y
        //Bounce from the top or bottom bound of the window
        _ballVelocity.y = -_ballVelocity.y;
    }
}

const sf::CircleShape &Ball::getShape() const { //shape getter
    return _shape;
}

void Ball::render(sf::RenderTarget *target) {

    target->draw(this->_shape); //draws a ball
}

void Ball::reset() { //resets ball parameters to initial ones
    _position[0] = _startingPosition[0];
    _position[1] = _startingPosition[1];
    _speed = 0;
    _ballVelocity.x = 0;
    _ballVelocity.y = 0;
    this->_shape.setPosition(_position[0],_position[1]); //gives back initial position and velocity
};

void Ball::loadTexture(const std::string& source) { //loads texture and handles errors
    if (!this->_texture.loadFromFile(source)) {
        std::cout << "Ball not added" << std::endl;
    } else {
        std::cout << "Ball added" << std::endl;
    }
}

void Ball::kick(float velocityX, float velocityY) { //sets velocity in given directions in order to move the ball
    _ballVelocity.x = velocityX;
    _ballVelocity.y = velocityY;
}

const sf::Vector2f &Ball::getBallVelocity() const { //ball velocity getter
    return _ballVelocity;
}

