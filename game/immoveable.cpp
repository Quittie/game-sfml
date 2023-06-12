
#include "immoveable.h"

#include <iostream>
#include <vector>


Immoveable::Immoveable(const std::string &source) { //class contructor
    _texture = new sf::Texture;
    _texture->loadFromFile(source);
    _sprite.setTexture(*_texture);
    _sprite.setScale(_scale[0], _scale[1]);
}

void Immoveable::render(sf::RenderTarget *target) { //renders Immoveable object
    target->draw(_sprite);
}

Immoveable::Immoveable(const std::string &source, const std::vector<float> &position, const std::vector<float> &size) : Immoveable(source){  //class contructor 2
    _position = position; //assigns position
    _sprite.setPosition(_position[0],_position[1]); //sets initial position
    _sprite.setScale(size[0] / _sprite.getGlobalBounds().width, size[1] / _sprite.getGlobalBounds().height); //sets scale
    _size = size; //assigns size
}

Immoveable::Immoveable(const std::vector<float> &position, const std::vector<float> &size) : Immoveable(){  //class contructor 3
    _position = position;
    _sprite.setPosition(_position[0],_position[1]);
    _sprite.setScale(size[0] / _sprite.getGlobalBounds().width, size[1] / _sprite.getGlobalBounds().height);  //class contructor 4
    _size = size;
}


const sf::Sprite &Immoveable::getSprite() const { //sprite getter
    return _sprite;
}

Immoveable::Immoveable() {  //class contructor 5

}

const std::vector<float> &Immoveable::getSize() const { //size getter
    return _size;
}
