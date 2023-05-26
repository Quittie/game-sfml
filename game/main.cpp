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

    while(game.isWindowOpen())
    {
//        while(game->window.poll)
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
