#ifndef GAME_H
#define GAME_H

#include "barricadem.h"
#include "hud.h"
#include "immoveable.h"
#include "moveable.h"
#include "player.h"

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
    void addI(const Immoveable &object);
    void addM(const Moveable &object);
    void addH(const hud &object);
    void showM();
    void show();
    void showI();
    bool isWindowOpen();
    void updating(Player &p);
    void rendering();
    void events(Player &p);
    sf::RenderWindow *getwindow();
    BarricadeM get(int number);
    void checkChances();
    void delHeart();
    void increaseScore();
    bool isGameFinished();

private:
    int time
    int _chances = 9;
    void variablesInit();
    void windowInit();
    void shapeInit();
    int _score=0;
    Player* player;
    sf::RenderWindow *window;
    sf::RectangleShape shape;
    sf::Event event;
    sf::Clock _clock;
    sf::Time _frameTime;
    std::vector<BarricadeM> _object;
    std::vector<std::unique_ptr<Immoveable>> _objectI; //unique pointers
    std::vector<std::unique_ptr<Moveable>> _objectM;
    std::vector<std::unique_ptr<hud>> _objectH;

};

#endif // GAME_H
