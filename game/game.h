#ifndef GAME_H
#define GAME_H

#include "barricadem.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>



class Game
{
public:
    Game();
    virtual ~Game();
    void add(const BarricadeM &object);
    void updating();
    void rendering();
    BarricadeM get(int number);

private:
    void variablesInit();
    void windowInit();

    sf::RenderWindow *window;
    sf::Event event;
    sf::Clock _clock;
    sf::Time _frameTime;
    std::vector<BarricadeM> _object;
};

#endif // GAME_H
