#include "game.h"
#include "barricadem.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

Game::Game()
{
    std::cout << "Let's start the game!" << std::endl;
    this->variablesInit();
    this->windowInit();
}

Game::~Game()
{
    delete this->window;
}
void Game::add(const BarricadeM &object)
{
    _object.push_back(object);
    std::cout << "Added successfully!" << std::endl;
}

bool Game::isWindowOpen()
{
    return this->window->isOpen();
}

void Game::updating()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
            {
                this->window->setSize(sf::Vector2u(800, 600));
            }
            break;

        case sf::Event::Closed:
            this->window->close();
            break;
        }
    }
}

void Game::rendering()
{
    this->window->clear();
    this->window->display();
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
