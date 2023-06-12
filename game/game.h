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
#include <SFML/Audio.hpp>

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
    bool play = true;
    bool add1 = true;
    bool add2 = true;
    bool reset = false;
    bool deathscreen = false;
    void windowInit();
    void playerInit();
    void barricadesInit();

    Immoveable *pitch;
    Player *player;
    Ball *ball;
    Immoveable *screen;
    Immoveable *gate;
    Immoveable *penaltyArea;
    Immoveable *playerArea;
    Goalkeeper *goalkeeper;
    sf::RenderWindow *window;
    sf::Event sfmlEvent;
    std::vector<std::unique_ptr<Immoveable>> objectsI;
    std::vector<std::unique_ptr<Barricade>> barricades;
    CounterWithText *goals;
    CounterWithText *time;
    ImmoveableCounter *attempts;
    ImmoveableCounter *hearts;
    sf::Text score;
    sf::Text sign;
    sf::Text finalSign;
    sf::Clock clock;
    sf::Time elapsed;
    sf::Music music;
    sf::Music trumpet;

    void ballInit();
    void updateCollision(bool& keyPressed);
    void resetGame();
    void showFinalSign();
    void createFinalSign();
    void checkPlayerArea();
    void showResults();
    void showSign();
    void createSign();
    void createResults();
    void loadMusic();
    void loadTrumpet();
    void stopMusic();
    void increaseLevel1();
    void increaseLevel2();
};

#endif // GAME_H

