#include "Player.h"


Player::Player(const std::vector<float> &position, const std::vector<float> &size, const std::string &source, float speed): Moveable(position, size, speed) //class constructor
{
    loadTexture(source); //loads texture
    loadSprite(); //loads sprite
}


void Player::animate(sf::Time &elapsed) //detects inputs and animates the player
{
    float dt = elapsed.asSeconds();
    if(dt>0.1&&dt<0.5)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::IntRect texturerect(1380, 1200, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::IntRect texturerect(920, 600, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::IntRect texturerect(920, 1810, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::IntRect texturerect(920, 0, 460, 590);
            this->_sprite.setTextureRect(texturerect);
        }
    }
    if(dt>=0.5&&dt<1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::IntRect texturerect(460, 1200, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::IntRect texturerect(0, 600, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::IntRect texturerect(0, 1810, 460, 600);
            this->_sprite.setTextureRect(texturerect);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            ||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::IntRect texturerect(0, 0, 460, 590);
            this->_sprite.setTextureRect(texturerect);
        }
    }
}

void Player::updateInput() { //detects inputs and moves the player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->_sprite.move(-this->_speed, 0.0f);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(this->_speed, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->_sprite.move(0.0f, -this->_speed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0.0f, this->_speed);

    }
}

void Player::updateWindowBoundsCollision(sf::RenderTarget *target) { //prevents the player from leaving the game window
    if(this->_sprite.getGlobalBounds().left <= 0.f)
        this->_sprite.setPosition(0.f,this->_sprite.getGlobalBounds().top);

    if(this->_sprite.getGlobalBounds().left + this ->_sprite.getGlobalBounds().width >= target->getSize().x)
        this->_sprite.setPosition(target -> getSize().x - this->_sprite.getGlobalBounds().width, this->_sprite.getGlobalBounds().top);

    if(this->_sprite.getGlobalBounds().top <= 0.f)
        this->_sprite.setPosition(this->_sprite.getGlobalBounds().left,0.f);

    if(this->_sprite.getGlobalBounds().top + this->_sprite.getGlobalBounds().height >= target -> getSize().y)
        this->_sprite.setPosition(this->_sprite.getGlobalBounds().left, target->getSize().y - this->_sprite.getGlobalBounds().height);
}

void Player::update(sf::RenderTarget *target){ //updates current state of the player
    this->updateInput();
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target) { //renders the player
    target ->draw(this->_sprite);
}

void Player::loadTexture(const std::string& source) { //loads texture from a specified file
    if (!this->_texture.loadFromFile(source)) {
        std::cout << "Player not added" << std::endl;
    } else {
        std::cout << "Player added" << std::endl;
    }
}

void Player::loadSprite() { //loads texture to the sprite and sets its parameters
    sf::IntRect textureRect(460, 0, 450, 590);

    _sprite.setTexture(_texture);
    _sprite.setTextureRect(textureRect);

    _sprite.setScale(_size[0] / _sprite.getGlobalBounds().width, _size[1] / _sprite.getGlobalBounds().height);
    _sprite.setPosition(this->_position[0], this->_position[1]);
}

const sf::Sprite &Player::getSprite() const { //sprite getter
    return _sprite;
}

void Player::reset() { //resets player's parameters
    _position[0] = _startingPosition[0];
    _position[1] = _startingPosition[1];
    _sprite.setPosition(this->_position[0], this->_position[1]);
}

void Player::updatePosition(float x, float y) { //sets new position
    _sprite.setPosition(x,y);
}

