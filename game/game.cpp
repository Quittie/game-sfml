
#include "game.h"
#include "barricadem.h"
#include "player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "pitch.h"

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

bool Game::isGameFinished()
{
//    if(time==0)
//    {
//        return false;
//    }
//    else
//    {
        return true;

}
void Game::increaseScore()
{
    _score++;
}

void Game::add(const BarricadeM &object)
{
    _object.push_back(object);
    std::cout << "Added successfully!" << std::endl;
}

void Game::addI(const Immoveable &object)
{
//    std::unique_ptr<Immoveable> newObj = std::make_unique<Immoveable>(object);
    _objectI.emplace_back(std::make_unique<Immoveable>(object));
    std::cout << "Added successfully!" << std::endl;
}

void Game::addM(const Moveable &object)
{
    _objectM.emplace_back(std::make_unique<Moveable>(object));
    std::cout << "Added successfully!" << std::endl;
}

void Game::addH(const hud &object)
{
    _objectH.emplace_back(std::make_unique<hud>(object));
    std::cout << "Added successfully!" << std::endl;
}

void Game::delHeart()
{
    _objectH.pop_back();
}

void Game::checkChances()
{
    if((_chances)%3==0&&_chances!=9)
    {
        delHeart();
    }
}


void Game::events(Player &p)
{
//    while(this->window->pollEvent(this->event))
//    {
//        switch(this->event.type)
//        {
//        case sf::Event::KeyPressed:
//            if(this->event.key.code == sf::Keyboard::Escape)
//            {
//                this->window->setSize(sf::Vector2u(800, 600));
//            }
//            if(this->event.key.code == sf::Keyboard::Right)
//            {
//                std::cout << "ASD" << std::endl;
//                p.getSprite().move(0, 7);
//            }

//        break;

//        case sf::Event::Closed:
//            this->window->close();
//            break;
//        }


//    }
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();


    }
}


void Game::show()
{
    for(auto& o : _object)
    {
        this->window->draw(*o.getRectangleShape());
    }
}

void Game::showI()
{
    for (auto& o : _objectI)
    {


        this->window->draw(o->getSprite());

    }
}


void Game::showM()
{
    for (auto& o : _objectM)
    {

        this->window->draw(o->getSprite());

    }
}

bool Game::isWindowOpen()
{
    return this->window->isOpen();
}

void Game::updating(Player &p)
{
    this->events(p);



}

void Game::rendering()
{

    this->window->clear();
    showI();
    show();
    showM();


    this->window->display();

}

void Game::variablesInit()
{
    this->window = nullptr;
}

void Game::windowInit()
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(desktopM, "Soccer Challenge 2k23", sf::Style::Titlebar | sf::Style::Close /*| sf::Style::Fullscreen*/);
    this->window->setFramerateLimit(120);
}

sf::RenderWindow* Game::getwindow()
{
    return window;
}
