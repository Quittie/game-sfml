#include "Player.h"


Player::Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed): Moveable(position, size, speed)
{
    loadTexture(source);
    loadSprite();
}


void Player::animate(sf::Time &elapsed)
{

}

void Player::updateInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->_sprite.move(-this->_speed, 0.0f);
        sf::IntRect texturerect(460, 1200, 460, 600);
        this->_sprite.setTextureRect(texturerect);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(this->_speed, 0.0f);
        sf::IntRect texturerect(920, 600, 460, 600);
        this->_sprite.setTextureRect(texturerect);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->_sprite.move(0.0f, -this->_speed);
        sf::IntRect texturerect(0, 1810, 460, 600);
        this->_sprite.setTextureRect(texturerect);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0.0f, this->_speed);
        sf::IntRect texturerect(0, 0, 460, 590);
        this->_sprite.setTextureRect(texturerect);
    }
}

void Player::updateWindowBoundsCollision(sf::RenderTarget *target) {
    if(this->_sprite.getGlobalBounds().left <= 0.f)
        this->_sprite.setPosition(0.f,this->_sprite.getGlobalBounds().top);

    if(this->_sprite.getGlobalBounds().left + this ->_sprite.getGlobalBounds().width >= target->getSize().x)
        this->_sprite.setPosition(target -> getSize().x - this->_sprite.getGlobalBounds().width, this->_sprite.getGlobalBounds().top);

    if(this->_sprite.getGlobalBounds().top <= 0.f)
        this->_sprite.setPosition(this->_sprite.getGlobalBounds().left,0.f);

    if(this->_sprite.getGlobalBounds().top + this->_sprite.getGlobalBounds().height >= target -> getSize().y)
        this->_sprite.setPosition(this->_sprite.getGlobalBounds().left, target->getSize().y - this->_sprite.getGlobalBounds().height);
}

void Player::update(sf::RenderTarget *target){
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target) {
    target ->draw(this->_sprite);
}

void Player::loadTexture(const std::string& source) {
    if (!this->_texture.loadFromFile(source)) {
        std::cout << "Player not added" << std::endl;
    } else {
        std::cout << "Player added" << std::endl;
    }
}

void Player::loadSprite() {
    sf::IntRect textureRect(460, 0, 450, 590);

    _sprite.setTexture(_texture);
    _sprite.setTextureRect(textureRect);

    _sprite.setScale(_size[0] / _sprite.getGlobalBounds().width, _size[1] / _sprite.getGlobalBounds().height);
    _sprite.setPosition(this->_position[0], this->_position[1]);
}

const sf::Sprite &Player::getSprite() const {
    return _sprite;
}

void Player::reset() {
    _position[0] = _startingPosition[0];
    _position[1] = _startingPosition[1];
    _sprite.setPosition(this->_position[0], this->_position[1]);
}

void Player::updatePosition(float x, float y) {
    _sprite.setPosition(x,y);
}

