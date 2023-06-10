
#ifndef IMMOVEABLE_H
#define IMMOVEABLE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <list>


class Immoveable : public sf::Sprite
{
public:
    Immoveable();
    Immoveable(const std::string &source);
    Immoveable(const std::string &source, const std::vector<float> &position, const std::vector<float> &size);
    Immoveable(const std::vector<float> &position, const std::vector<float> &size);
    const Sprite &getSprite() const;

    const std::vector<float> &getSize() const;

    void render(sf::RenderTarget* target);
protected:
    sf::Texture* _texture;
    sf::Sprite _sprite;
    std::vector<float> _size;
    std::vector<float> _position  = {0,0};
    std::vector<float> _scale  = {1,1};
};

#endif // IMMOVEABLE_H
