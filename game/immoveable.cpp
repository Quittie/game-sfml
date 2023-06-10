#include "immoveable.h"

#include <iostream>
#include <vector>


Immoveable::Immoveable(const std::string &source) {
    if (!_texture.loadFromFile(source)) {
        std::cout << "Immoveable not added" << std::endl;
    } else {
        std::cout << "Immoveable added" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setScale(_scale[0], _scale[1]);
}

void Immoveable::render(sf::RenderTarget *target) {
    target->draw(_sprite);
}

Immoveable::Immoveable(const std::string &source, const std::vector<float> &position, const std::vector<float> &size) : Immoveable(source){
    _position = position;
    _sprite.setPosition(_position[0],_position[1]);
    _sprite.setScale(size[0] / _sprite.getGlobalBounds().width, size[1] / _sprite.getGlobalBounds().height);
}

Immoveable::Immoveable(const std::vector<float>& position, const std::vector<float>& size, const sf::Texture& texture) {
    sf::Texture objectTexture;
    objectTexture.loadFromImage(texture.copyToImage());
    _position = position;
    _sprite.setPosition(_position[0], _position[1]);
    _sprite.setScale(size[0] / objectTexture.getSize().x, size[1] / objectTexture.getSize().y);
    _texture = objectTexture;  // Usuń przypisanie wskaźnika _texture
    _sprite.setTexture(_texture);
}

const sf::Sprite &Immoveable::getSprite() const {
    return _sprite;
}
