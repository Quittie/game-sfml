
#include "immoveable.h"

#include <iostream>
#include <vector>


Immoveable::Immoveable(const std::string &source) {
    _texture = new sf::Texture;
    _texture->loadFromFile(source);
    _sprite.setTexture(*_texture);
    _sprite.setScale(_scale[0], _scale[1]);
}

void Immoveable::render(sf::RenderTarget *target) {
    target->draw(_sprite);
}

Immoveable::Immoveable(const std::string &source, const std::vector<float> &position, const std::vector<float> &size) : Immoveable(source){
    _position = position;
    _sprite.setPosition(_position[0],_position[1]);
    _sprite.setScale(size[0] / _sprite.getGlobalBounds().width, size[1] / _sprite.getGlobalBounds().height);
    _size = size;
}

Immoveable::Immoveable(const std::vector<float> &position, const std::vector<float> &size) : Immoveable(){
    _position = position;
    _sprite.setPosition(_position[0],_position[1]);
    _sprite.setScale(size[0] / _sprite.getGlobalBounds().width, size[1] / _sprite.getGlobalBounds().height);
    _size = size;
}


const sf::Sprite &Immoveable::getSprite() const {
    return _sprite;
}

Immoveable::Immoveable() {

}

const std::vector<float> &Immoveable::getSize() const {
    return _size;
}
