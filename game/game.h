#ifndef GAME_H
#define GAME_H

#include "barricadem.h"
#include "immoveable.h"
#include "moveable.h"
#include "player.h"
#include "Ball.h"
#include "ImmoveableCounter.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>



class Game
{
public:
    Game();
    virtual ~Game();
    void update(float dt);
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
    sf::RenderWindow *window;
    sf::RectangleShape shape;
    sf::Event sfmlEvent;
    sf::Clock _clock;
    sf::Time _frameTime;
    std::vector<std::unique_ptr<Barricade>> barricades;
    ImmoveableCounter *goals;
    ImmoveableCounter * attempts;
    ImmoveableCounter *hearts;
    void ballInit();
    void updateCollision();
    void resetGame();
    int score = 0;
};

#endif // GAME_H

