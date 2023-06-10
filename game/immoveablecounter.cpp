#include <memory>
#include "ImmoveableCounter.h"

ImmoveableCounter::ImmoveableCounter(const std::string &source1,const std::string &source2, const std::vector<float> &position,
                                     const std::vector<float> &size, int counter) {

    sf::Texture texture;
    if (!texture.loadFromFile(source1)) {
        // Error handling if the texture fails to load
    }

    // TODO:
    float x = position[0];
    for (int i = 0; i < counter; i++) {
        Immoveable immoveableObj({x, position[1]}, size, texture);
        x = x + size[0];
        _immoveables.push_back(immoveableObj);
    }
}

int ImmoveableCounter::getCounter() const {
    return counter;
}

void ImmoveableCounter::setCounter(int newCounter) {
    ImmoveableCounter::counter = newCounter;
}

void ImmoveableCounter::render(sf::RenderTarget *window) {
    for (auto immoveable: this->_immoveables) {
        immoveable.render(window);
    }
}
