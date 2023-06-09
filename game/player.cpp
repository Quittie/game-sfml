
#include "Player.h"


Player::Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, int velocity):Moveable(position, size, velocity)
{
    _position = position;
    _size = size;

    if(!this->_texture.loadFromFile(source))
    {
        std::cout << "Player not added" << std::endl;
    }
    else
    {
        std::cout << "Player added" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setScale(_size[0] / _sprite.getGlobalBounds().width, _size[1] / _sprite.getGlobalBounds().height);
    _sprite.setPosition(position[0], position[1]);
    _source = source;
    _velocity = velocity;

}



void Player::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->_sprite.move(-this->_velocity, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->_sprite.move(this->_velocity, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->_sprite.move(0.f, -this->_velocity);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->_sprite.move(0.f, this->_velocity);

    }

}

//    sf::Event event;
//    while (game->getwindow()->pollEvent(event))
//    {
//        std::cout << "1" << std::endl;
//        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
//        {
//            std::cout << "w" << std::endl;
//            _sprite.setPosition(800, 800);
//        }

//    if(event.type == sf::Event::Closed)
//    {
//        game->getwindow()->close();
//    }
//    _position[0] += _velocity;
//    _position[1] += _velocity;
//    _sprite.setPosition(_position[0], _position[1]);


//}
//void Player::move(Game *game)
//{
//    sf::Event event;
//    while (game->getwindow()->pollEvent(event))
//    {
//        if (event.type == sf::Event::KeyPressed)
//        {
//            std::cout << "Nienawidze infy" << std::endl;
//            if (event.key.code == sf::Keyboard::Left)
//            {
//                std::cout << "dupa" << std::endl;
//                _sprite.move(-5, 0);
//            }
//            else if (event.key.code == sf::Keyboard::Right)
//                _sprite.move(5, 0);
//            else if (event.key.code == sf::Keyboard::Up)
//                _sprite.move(0, -5);
//            else if (event.key.code == sf::Keyboard::Down)
//                _sprite.move(0, 5);
//        }
//        else if (event.type == sf::Event::Closed)
//        {
//            game->getwindow()->close();
//        }
//    }
//}

sf::Sprite  Player::getSprite()
{
    return _sprite;
}


//bool Player::checkBounds(){return true;}
