
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

void Player::move()
{
    sf::Event event;
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
            _player.move(-5, 0);
        else if (event.key.code == sf::Keyboard::Right)
            _player.move(5, 0);
        else if (event.key.code == sf::Keyboard::Up)
            _player.move(0, -5);
        else if (event.key.code == sf::Keyboard::Down)
            _player.move(0, 5);
    }
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
