#include "CounterWithText.h"

CounterWithText::CounterWithText(const std::string &source1, const std::vector<float> &position, //class constructor
                                 const std::vector<float> &size, int counter) {
    _counter = counter; //goal or time counter
    _startingCounter = counter; //initial counter number
    _immoveable = Immoveable(source1, position, size); //displayed symbol constructor
    _scoreText = new sf::Text; //sf::Text object
    _scoreText->setString(std::to_string(counter)); //casting from int counter to string and setting this string to sf::Text object
    _font = new sf::Font;
    if (!_font->loadFromFile("arial.ttf")) { //loading font from file
        // Error handling if the font fails to load
    }
    _scoreText->setFont(*_font); //setting font for sf::Text object
    _scoreText->setPosition({position[0]+ size[0] + 10,position[1] - 10}); //setting position of this object
    _scoreText->setFillColor(sf::Color::Black); //setting colour
    _scoreText->setCharacterSize(size[1]); //setting the size of characters
}

int CounterWithText::getCounter() const { //counter getter
    return _counter;
}

void CounterWithText::render(sf::RenderTarget *window) { //renders the counter
    _immoveable.render(window);
    _scoreText->setString(std::to_string(_counter)); //casts current counter state to string and sets it for sf::Text object
    window->draw(*_scoreText); //shows it on the screen
}

void CounterWithText::increaseCounter() { //increases counter
    this->_counter++;
}

void CounterWithText::reset() {
    this->_counter = _startingCounter; //resets counter
}

void CounterWithText::decreaseCounter() { //decreases counter
    this->_counter--;
}

