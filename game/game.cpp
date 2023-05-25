
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

void Game::start()
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopM, "Soccer Challenge 2k23");

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);


        // end the current frame
        window.display();
    }

}
