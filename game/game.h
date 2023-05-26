
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
    void start();
    void stop();
    const bool isWindowOpen() const;
    void add(const BarricadeM &object);
    BarricadeM get(int number);

private:
    std::vector<BarricadeM> _object;
    sf::Clock _clock;
    sf::Time _frameTime;
};

#endif // GAME_H
