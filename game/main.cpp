#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
#include <iostream>
#include <string>

#include "moveable.h"
#include "game.h"
#include "barricadem.h"
#include "pitch.h"
#include "player.h"

int main()
{
    Game game;

    BarricadeM b1({200, 324}, {50, 234}, {103, 35, 0}, 60);
    BarricadeM b2({100, 524}, {50, 500}, {103, 35, 0}, -60);
    BarricadeM b3({300, 424}, {50, 456}, {103, 35, 0}, -40);
    BarricadeM b4({1000, 624}, {50, 100}, {103, 35, 0}, 80);
    BarricadeM b5({800, 524}, {50, 523}, {103, 35, 0}, 90);
    BarricadeM b6({700, 563}, {50, 400}, {103, 35, 0}, -100);
    BarricadeM b7({600, 400}, {50, 350}, {103, 35, 0}, -20);
    BarricadeM b8({400, 500}, {50, 200}, {103, 35, 0}, 35);
    BarricadeM b9({400, 500}, {50, 200}, {103, 35, 0}, 35);

    Pitch pitch("trawka.png", {0, 0}, {2.5, 2.5});

    Player player({200, 200}, {500, 500}, "ball.png", 90);

    game.add(b1);
    game.add(b2);
    game.add(b3);
    game.add(b4);
    game.add(b5);
    game.add(b6);
    game.add(b7);
    game.add(b8);
    game.addI(pitch);
    game.addM(player);


    while(game.isWindowOpen())
    {
        b1.moveBarricade(&game);
        b2.moveBarricade(&game);
        b3.moveBarricade(&game);
        b4.moveBarricade(&game);
        b5.moveBarricade(&game);
        b6.moveBarricade(&game);
        b7.moveBarricade(&game);
        b8.moveBarricade(&game);
        player.move();

        game.updating(player);
        player.move();

        game.rendering();

    }
    return 0;
}


