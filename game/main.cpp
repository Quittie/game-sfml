#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
#include <iostream>
#include <string>

#include "moveable.h"
#include "game.h"
#include "barricadem.h"

int main()
{
    Game game;

    BarricadeM b1({200, 324}, {50, 234}, {103, 35, 0}, 60);
    BarricadeM b2({100, 524}, {50, 500}, {103, 35, 0}, -60);
    BarricadeM b3({300, 424}, {50, 456}, {103, 35, 0}, -40);
    BarricadeM b4({200, 624}, {50, 100}, {103, 35, 0}, 80);
    BarricadeM b5({800, 524}, {50, 523}, {103, 35, 0}, 90);
    BarricadeM b6({700, 563}, {50, 400}, {103, 35, 0}, -100);
    BarricadeM b7({600, 400}, {50, 350}, {103, 35, 0}, -20);
    BarricadeM b8({400, 500}, {50, 200}, {103, 35, 0}, 35);

    game.add(b1);
    game.add(b2);
    game.add(b3);
    game.add(b4);
    game.add(b5);
    game.add(b6);
    game.add(b7);
    game.add(b8);


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
        game.updating();

        game.rendering();
    }
    return 0;
}


//    std::vector<float> position { 100.0f, 100.0f };
//    std::vector<float> size { 50.0f, 50.0f };
//    std::vector<float> colour { 255.0f, 0.0f, 0.0f };

//    std::vector<float> position1 { 739.0f, 452.0f };
//    std::vector<float> size1 { 569.0f, 1000.0f };
//    std::vector<float> colour1 { 65.0f, 186.6f, 172.0f };
//    BarricadeM barricade(position, size, colour);
//    BarricadeM barricade1(position1, size1, colour1);

//    game.add(barricade);
//    game.add(barricade1);
//    game.start();

//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>

//int main()
//{





//    bool movingUpR = true;
//    bool movingUpG = true;
//    bool movingUpB = true;
//    float yPosG = rectangleG.getPosition().y;
//    float yPosR = rectangleR.getPosition().y;
//    float yPosB = rectangleB.getPosition().y;

//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }

//        // Move the rectangle up and down
//        if (movingUpR)
//        {
//            yPosR -= 0.05f;
//            if (yPosR < 0)
//                movingUpR = false;
//        }
//        else
//        {
//            yPosR += 0.05f;
//            if (yPosR > 400)
//                movingUpR = true;
//        }

//        if (movingUpG)
//        {
//            yPosG -= 0.10f;
//            if (yPosG < 0)
//                movingUpG = false;
//        }
//        else
//        {
//            yPosG += 0.10f;
//            if (yPosG > 400)
//                movingUpG = true;
//        }

//        if (movingUpB)
//        {
//            yPosB -= 0.15f;
//            if (yPosB < 0)
//                movingUpB = false;
//        }
//        else
//        {
//            yPosB += 0.15f;
//            if (yPosB > 400)
//                movingUpB = true;
//        }

//        rectangleR.setPosition(rectangleR.getPosition().x, yPosR);
//        rectangleG.setPosition(rectangleG.getPosition().x, yPosG);
//        rectangleB.setPosition(rectangleB.getPosition().x, yPosB);

//        window.clear();
//        window.draw(rectangleG);
//        window.draw(rectangleR);
//        window.draw(rectangleB);
//        window.display();
//    }

//    return 0;
//}
