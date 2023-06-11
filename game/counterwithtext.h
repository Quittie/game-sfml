#ifndef GAME_COUNTERWITHTEXT_H
#define GAME_COUNTERWITHTEXT_H


#include <SFML/Graphics/Text.hpp>
#include "immoveable.h"

class CounterWithText {
public:
    CounterWithText(const std::string &source1, const std::vector<float> &position, const std::vector<float> &size,
                    int counter);
private:
    Immoveable _immoveable;
    int _counter;
    int _startingCounter;
    sf::Text* _scoreText;
    sf::Font* _font;
public:
    int getCounter() const;
    void render(sf::RenderTarget *window);
    void increaseCounter();
    void decreaseCounter();
    void reset();
};


#endif //GAME_COUNTERWITHTEXT_H
