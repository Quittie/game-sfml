
#include "Player.h"

Player::Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source):Moveable(position, size)
{
    _position = position;
    _size = size;
    _source = source;
//    if(!this->_texture.loadFromFile(_source))
//    {
//        std::cout << "Added successfully!" << std::endl;
//    }
//    _player.setTexture(_texture);
//    _player.setTextureRect(sf::IntRect(0, 0, 64, 64));

}

sf::Sprite Player::getSprite()
{
    return _player;
}

sf::Texture Player::getTexture()
{
    return _texture;
}



//bool Player::checkBounds(){return true;}
