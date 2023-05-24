
#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>


class Game:public sf::Sprite
{
public:
    Game();
    void add(const sf::Sprite &object);
    sf::Sprite get(int number);
private:
    std::vector<sf::Sprite> _object;
};

#endif // GAME_H
