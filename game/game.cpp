
#include "game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "barricadem.h"

Game::Game()
{

}
void Game::add(const BarricadeM &object)
{
    _object.push_back(object);
    std::cout << "Added successfully!" << std::endl;
}
//sf::Sprite Game::get(int number)
//{
//    return _object[number];
//}

void Game::start()
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopM, "Soccer Challenge 2k23", sf::Style::Titlebar | sf::Style::Close/* | sf::Style::Fullscreen*/);

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
//            if (event.key.code == sf::Keyboard::Escape)
//            {
//                window.setSize(sf::Vector2u(800, 1200));

//            }
        }



        // clear the window with black color
        window.clear(sf::Color::Black);

//        for(auto &o : _object)
//        {
////            window.draw(o.getRectangleShape());
////            o.moveBarricade();
//        }


        // end the current frame
        window.display();
    }

}
//const bool Game::isWindowOpen() const
//{
//    return window.isOpen();
//}

void Game::stop()
{

}

void Game::updating()
{

}

void Game::rendering()
{

}

void Game::variablesInit()
{
    this->window = nullptr;

}

void Game::windowInit()
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(desktopM, "Soccer Challenge 2k23", sf::Style::Titlebar | sf::Style::Close/* | sf::Style::Fullscreen*/);
}
