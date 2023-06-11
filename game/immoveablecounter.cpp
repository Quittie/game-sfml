#include <memory>
#include "ImmoveableCounter.h"

ImmoveableCounter::ImmoveableCounter(const std::string &source1, const std::vector<float> &position,
                                     const std::vector<float> &size, int counter) {

    float x = position[0];
    _counter = counter;
    _startingCounter = counter;
    for (int i = 0; i < _counter; i++) {
        _immoveables.push_back(Immoveable(source1, {x,position[1]}, size));
        x = x + size[0];
    }
}

int ImmoveableCounter::getCounter() const {
    return _counter;
}

void ImmoveableCounter::render(sf::RenderTarget *window) {
    for (int i = 0; i < _counter; ++i) {
        _immoveables[i].render(window);
    }
}

void ImmoveableCounter::decreaseCounter() {
    this->_counter--;
}

void ImmoveableCounter::reset() {
    this->_counter = _startingCounter;
}
