#ifndef GAME_IMMOVEABLECOUNTER_H
#define GAME_IMMOVEABLECOUNTER_H


#include "immoveable.h"
#include <memory>

class ImmoveableCounter {
public:
    ImmoveableCounter(const std::string &source1, const std::string &source2, const std::vector<float> &position, const std::vector<float> &size,
                      int counter);

private:
    std::vector<Immoveable> _immoveables;
    int counter;
    std::vector<std::shared_ptr<sf::Texture>> textures;
public:
    int getCounter() const;
    void setCounter(int newCounter);
    void render(sf::RenderTarget *window);
};


#endif //GAME_IMMOVEABLECOUNTER_H
