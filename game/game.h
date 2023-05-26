
#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "barricadem.h"


class Game
{
public:
    Game();
    virtual ~Game();
//    void start();
//    void stop();
    const bool isWindowOpen();
    void add(const BarricadeM &object);
    void updating();
    void rendering();
    BarricadeM get(int number);

private:
    sf::RenderWindow *window;
    sf::Event event;
    void variablesInit();
    void windowInit();
    std::vector<BarricadeM> _object;
    sf::Clock _clock;
    sf::Time _frameTime;
};

#endif // GAME_H
