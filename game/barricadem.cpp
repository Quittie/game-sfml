#include "barricadem.h"
#include "moveable.h"

#include <vector>

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size, const std::vector<sf::Uint8> &colour, float speed, bool movingUp):
    Moveable(position, size, speed) //barricade contructor
{
    this->_rectangleShape = sf::RectangleShape(sf::Vector2f(size[0], size[1])); //assigns RectangleShape to _rectagnleShape with the size given
    this->_rectangleShape.setPosition(sf::Vector2f(position[0], position[1])); //sets initial position
    if(!colour.empty()) {
        this->_rectangleShape.setFillColor(sf::Color(colour[0], colour[1], colour[2])); //sets a colour provided by user
    }
    this->movingUp = movingUp; //decides if object initially moves up or down
}

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size, //version 2 of the constructor
                     const std::vector<sf::Uint8> &colour, float speed, bool movingUp, const std::string &source) : Barricade::Barricade(position, size, colour, speed, movingUp){
    loadTexture(source);
    _rectangleShape.setTexture(&_texture);
}

Barricade::Barricade(const std::vector<float> &position, const std::vector<float> &size, //version 3 of the constructor
                     const std::vector<sf::Uint8> &colour, float speed, const std::string &source) : Barricade::Barricade(position, size, colour, speed, true, source){

}

void Barricade::moveBarricade(sf::RenderTarget *target) { //moves barricade
    float windowHeight = target->getSize().y; //gets y size of the window and assigns it to windowHeight parameter
    if (movingUp) { //if barricade is to move up
        _position[1] -= _speed;
        _rectangleShape.setPosition(_position[0], _position[1]); //moves it up
        if (_position[1] <= 0) { //when barricades rechaes the top edge of the window
            movingUp = false; //changes the flag in order to bounce it
        }
    } else { //if barricade is to move down
        _position[1] += _speed;
        _rectangleShape.setPosition(_position[0], _position[1]); //moves it down
        if (_position[1] + _rectangleShape.getSize().y >= windowHeight) { //when barricades rechaes the bottom edge of the window
            movingUp = true; //changes the flag in order to bounce it
        }
    }
}

void Barricade::update(sf::RenderTarget *target) {
    this->moveBarricade(target); //moves the barricade
}

void Barricade::render(sf::RenderTarget *target) {
    target->draw(this->_rectangleShape); //draws it on the screen
}

const sf::RectangleShape &Barricade::getRectangleShape() const {
    return _rectangleShape; //_rectangleShape getter
}

void Barricade::loadTexture(const std::string& source) { //loads texture and informs about errors or successes
    if (!_texture.loadFromFile(source)) {
        std::cout << "Barricade not added" << std::endl;
    } else {
        std::cout << "Barricade added" << std::endl;
    }
}
