#ifndef GAME_H
#define GAME_H

#include "barricadem.h"
#include "immoveable.h"
#include "moveable.h"
#include "player.h"
#include "Ball.h"
#include "ImmoveableCounter.h"
#include "CounterWithText.h"
#include "Goalkeeper.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>



class Game
{
public:
    Game();
    virtual ~Game();
    void update(bool &keyPressed);
    void render();
    bool running() const;
    void pollEvents();

private:
    void variablesInit();
    void windowInit();
    void playerInit();
    void barricadesInit();
    bool reset = false;
    Immoveable *pitch;
    Player *player;
    Ball *ball;
    Immoveable *gate;
    Immoveable *penaltyArea;
    Immoveable *playerArea;
    Goalkeeper *goalkeeper;
    sf::RenderWindow *window;
    sf::Event sfmlEvent;
    std::vector<std::unique_ptr<Barricade>> barricades;
    CounterWithText *goals;
    CounterWithText *time;
    ImmoveableCounter *attempts;
    ImmoveableCounter *hearts;
    sf::Clock clock;
    sf::Time elapsed;
    void ballInit();
    void updateCollision(bool& keyPressed);
    void resetGame();

    void checkPlayerArea();
};

#endif // GAME_H

