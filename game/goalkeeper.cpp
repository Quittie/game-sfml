#include "Goalkeeper.h"

Goalkeeper::Goalkeeper(const std::vector<float> &position, const std::vector<float> &size,
                       const std::vector<sf::Uint8> &colour, float speed, const std::string &source) : Barricade(
        position, size, colour, speed, source) {
}

void Goalkeeper::update(std::vector<float> penaltyAreaSize, const sf::Vector2f penaltyAreaPosition) {
    // Generowanie losowego kierunku ruchu
    int directionX = std::rand() % 3 - 1; // -1, 0, 1
    int directionY = std::rand() % 3 - 1; // -1, 0, 1

    float minX = penaltyAreaPosition.x;
    float minY = penaltyAreaPosition.y;
    float maxX = penaltyAreaPosition.x + penaltyAreaSize[0] - _rectangleShape.getSize().x;
    float maxY = penaltyAreaPosition.y + penaltyAreaSize[1] - _rectangleShape.getSize().y;

    _position[0] += directionX * _speed;
    _position[1] += directionY * _speed;

    // Sprawdzanie ograniczeń ruchu w osi X
    if (_position[0] < minX)
        _position[0] = minX;
    else if (_position[0] > maxX)
        _position[0] = maxX;

    // Sprawdzanie ograniczeń ruchu w osi Y
    if (_position[1] < minY)
        _position[1] = minY;
    else if (_position[1] > maxY)
        _position[1] = maxY;

    _rectangleShape.setPosition(_position[0], _position[1]);
}


