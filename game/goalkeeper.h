#ifndef GAME_GOALKEEPER_H
#define GAME_GOALKEEPER_H


#include "barricadem.h"

class Goalkeeper : public Barricade {
public:
    Goalkeeper(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour,
               float speed, const std::string &source);
    void update(std::vector<float> penaltyArea, const sf::Vector2f penaltyAreaPosition);



};


#endif //GAME_GOALKEEPER_H
