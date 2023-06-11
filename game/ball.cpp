
#include <valarray>
#include "Ball.h"

Ball::Ball(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed) : Moveable(position, size, speed) {
    loadTexture(source);
    _shape.setTexture(&_texture);
    _shape.setPosition(this->_position[0], this->_position[1]);
    _shape.setRadius(25);
    _ballVelocity = sf::Vector2f (0, 0);
}

void Ball::update(sf::RenderTarget *target) {
    this->updateKick();
    this->updateWindowBoundsCollision(target);
}

void Ball::updateKick() {
    _shape.move(_ballVelocity);

}

void Ball::updateWindowBoundsCollision(sf::RenderTarget *target) {
    sf::FloatRect ballBounds = getShape().getGlobalBounds();
    if (ballBounds.left <= 0.f || ballBounds.left + ballBounds.width  >= target->getSize().x) {
        // Odbicie od lewej lub prawej krawędzi
        _ballVelocity.x = -_ballVelocity.x;
    }

    if (ballBounds.top <= 0.f || ballBounds.top + ballBounds.height >= target->getSize().y) {
        // Odbicie od górnej lub dolnej krawędzi
        _ballVelocity.y = -_ballVelocity.y;
    }
}

const sf::CircleShape &Ball::getShape() const {
    return _shape;
}

void Ball::render(sf::RenderTarget *target) {

    target->draw(this->_shape);
}

void Ball::reset() {
    _position[0] = _startingPosition[0];
    _position[1] = _startingPosition[1];
    _speed = 0;
    _ballVelocity.x = 0;
    _ballVelocity.y = 0;
    this->_shape.setPosition(_position[0],_position[1]);
};

void Ball::loadTexture(const std::string& source) {
    if (!this->_texture.loadFromFile(source)) {
        std::cout << "Ball not added" << std::endl;
    } else {
        std::cout << "Ball added" << std::endl;
    }
}

void Ball::kick(float velocityX, float velocityY) {
    _ballVelocity.x = velocityX;
    _ballVelocity.y = velocityY;
}

const sf::Vector2f &Ball::getBallVelocity() const {
    return _ballVelocity;
}

