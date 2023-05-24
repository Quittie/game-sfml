
#include "game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

Game::Game()
{

}
void Game::add(const sf::Sprite &object)
{
    _object.push_back(object);
    std::cout << "Added successfully!" << std::endl;
}
sf::Sprite Game::get(int number)
{
    return _object[number];
}
