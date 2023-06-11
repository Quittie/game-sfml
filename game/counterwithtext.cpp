#include "CounterWithText.h"

CounterWithText::CounterWithText(const std::string &source1, const std::vector<float> &position,
                                 const std::vector<float> &size, int counter) {
    _counter = counter;
    _startingCounter = counter;
    _immoveable = Immoveable(source1, position, size);
    _scoreText = new sf::Text;
    _scoreText->setString(std::to_string(counter));
    _font = new sf::Font;
    if (!_font->loadFromFile("arial.ttf")) {
        // Error handling if the font fails to load
    }
    _scoreText->setFont(*_font);
    _scoreText->setPosition({position[0]+ size[0] + 10,position[1] - 10});
    _scoreText->setFillColor(sf::Color::Black);
    _scoreText->setCharacterSize(size[1]);
}

int CounterWithText::getCounter() const {
    return _counter;
}

void CounterWithText::render(sf::RenderTarget *window) {
    _immoveable.render(window);
    _scoreText->setString(std::to_string(_counter));
    window->draw(*_scoreText);
}

void CounterWithText::increaseCounter() {
    this->_counter++;
}

void CounterWithText::reset() {
    this->_counter = _startingCounter;
}

void CounterWithText::decreaseCounter() {
    this->_counter--;
}

