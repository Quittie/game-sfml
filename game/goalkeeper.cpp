#include "Goalkeeper.h"

Goalkeeper::Goalkeeper(const std::vector<float> &position, const std::vector<float> &size,
                       const std::vector<sf::Uint8> &colour, float speed, const std::string &source) : Barricade(
        position, size, colour, speed, source) {
} //class contructor which sets initial position, size, colour, speed and file source of the goalkeeper

void Goalkeeper::update(std::vector<float> penaltyAreaSize, const sf::Vector2f penaltyAreaPosition) {
    // generates random movement direction
    int directionX = std::rand() % 3 - 1; // -1, 0, 1 random teleportation in x and y direcitions
    int directionY = std::rand() % 3 - 1; // -1, 0, 1

    float minX = penaltyAreaPosition.x - 50; //goalkeeper area restrictions
    float minY = penaltyAreaPosition.y - 50;
    float maxX = penaltyAreaPosition.x + penaltyAreaSize[0] - 100 - _rectangleShape.getSize().x;
    float maxY = penaltyAreaPosition.y + 50 + penaltyAreaSize[1] - _rectangleShape.getSize().y;

    _position[0] += directionX * _speed; //assigns new positions
    _position[1] += directionY * _speed;

    //checks restrictions of move in the x axis
    if (_position[0] < minX)
        _position[0] = minX; //checks if goalkeeper 'wants' to leave his area
    else if (_position[0] > maxX)
        _position[0] = maxX;

    //checks restrictions of move in the y axis
    if (_position[1] < minY)
        _position[1] = minY;
    else if (_position[1] > maxY)
        _position[1] = maxY;

    _rectangleShape.setPosition(_position[0], _position[1]); //sets new random position
}


