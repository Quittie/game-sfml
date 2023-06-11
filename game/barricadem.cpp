#include "barricadem.h"
#include "moveable.h"
#include "game.h"

#include <vector>

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour, float speed, bool movingUp):
    Moveable(position, size, speed)
{
    this->_rectangleShape = sf::RectangleShape(sf::Vector2f(size[0], size[1]));
    this->_rectangleShape.setPosition(sf::Vector2f(position[0], position[1]));
    if(!colour.empty()) {
        this->_rectangleShape.setFillColor(sf::Color(colour[0], colour[1], colour[2]));
    }
    this->movingUp = movingUp;
}

void Barricade::moveBarricade(sf::RenderTarget *target) {
    float windowHeight = target->getSize().y;
    if (movingUp) {
        _position[1] -= _speed;
        _rectangleShape.setPosition(_position[0], _position[1]);
        if (_position[1] <= 0) {
            movingUp = false;
        }
    } else {
        _position[1] += _speed;
        _rectangleShape.setPosition(_position[0], _position[1]);
        if (_position[1] + _rectangleShape.getSize().y >= windowHeight) {
            movingUp = true;
        }
    }
}

void Barricade::update(sf::RenderTarget *target) {
    this->moveBarricade(target);
}

void Barricade::render(sf::RenderTarget *target) {
    target->draw(this->_rectangleShape);
}

const sf::RectangleShape &Barricade::getRectangleShape() const {
    return _rectangleShape;
}

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size,
                     const std::vector<sf::Uint8> &colour, float speed, bool movingUp, const std::string &source) : Barricade::Barricade(position, size, colour, speed, movingUp){
    loadTexture(source);
    _rectangleShape.setTexture(&_texture);
}

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size,
                     const std::vector<sf::Uint8> &colour, float speed, const std::string &source) : Barricade::Barricade(position, size, colour, speed, true, source){

}

const void Barricade::loadTexture(const std::string& source) {
    if (!_texture.loadFromFile(source)) {
        std::cout << "Barricade not added" << std::endl;
    } else {
        std::cout << "Barricade added" << std::endl;
    }
}
