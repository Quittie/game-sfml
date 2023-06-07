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

void Game::events(Player &p)
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
            if(this->event.key.code == sf::Keyboard::Right)
            {
                std::cout << "ASD" << std::endl;
                p.getSprite().move(0, 7);
            }

        break;

        case sf::Event::Closed:
            this->window->close();
            break;
        }


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
//        if (auto pitch = dynamic_cast<Pitch*>(&o)) // Sprawdź, czy obiekt jest instancją klasy Pitch
//        {
//            this->window->draw(pitch->getSprite()); // Wyświetl sprite obiektu Pitch
//        }

        this->window->draw(o->getSprite());

    }
}


void Game::showM()
{
    for (auto& o : _objectM)
    {

        this->window->draw(o->getSprite()); // Wyświetl sprite obiektu Pitch

    }
}

bool Game::isWindowOpen()
{
    return this->window->isOpen();
}

void Game::updating(Player &p)
{
    this->events(p);



//    for (auto& object : _objectM)
//    {
//        Player* player = dynamic_cast<Player*>(object.get());
//        if (player)
//        {
//            player->move(this);
//            player->setPosition(player->getSprite().getPosition());
//        }
//    }
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

//void Game::shapeInit()
//{
//    this->shape.
//}
