
#include "game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

game::game()
{

}
void game::add(const sf::Sprite &object)
{
    _object.push_back(object);
}
sf::Sprite game::get(int number)
{
    return _object[number];
}
