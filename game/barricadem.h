#ifndef BARRICADEM_H
#define BARRICADEM_H

#include <vector>
#include "moveable.h"

class Game;

class Barricade : public Moveable
{
public:
    Barricade(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour, float speed, bool movingUp);
    Barricade(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour, float speed, bool movingUp, const std::string &source);
    Barricade(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour, float speed, const std::string &source);
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget* target);

    const sf::RectangleShape &getRectangleShape() const;

protected:
    sf::RectangleShape _rectangleShape;
private:
    void moveBarricade(sf::RenderTarget *target);
    bool movingUp;

    const void loadTexture(const std::string &source);
};

#endif // BARRICADEM_H
