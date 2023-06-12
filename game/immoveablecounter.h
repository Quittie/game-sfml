#ifndef GAME_IMMOVEABLECOUNTER_H
#define GAME_IMMOVEABLECOUNTER_H


#include "immoveable.h"
#include <memory>

class ImmoveableCounter : public sf::Sprite{
public:
    ImmoveableCounter(const std::string &source1, const std::vector<float> &position, const std::vector<float> &size,
                      int counter);

private:
    std::vector<Immoveable> _immoveables;
    int _counter;
    int _startingCounter;
public:
    int getCounter() const;
    void render(sf::RenderTarget *window);
    void decreaseCounter();
    void reset();
};


#endif //GAME_IMMOVEABLECOUNTER_H
