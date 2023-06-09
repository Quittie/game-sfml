
#ifndef HUD_H
#define HUD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>




class hud : public sf::Sprite
{
public:
    hud(const std::vector<float> &position, const std::vector<float> &size, const std::string &source);
    sf::Sprite getHUD();
protected:
    std::vector<float> _position;
    std::vector<float> _scale;
    std::string _source;
    sf::Sprite _hud_object;
    sf::Texture _texture;

};

#endif // HUD_H
