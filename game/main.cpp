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
    std::vector<float> vec = {23, 234, 23};
    std::vector<float> vec2 = {23, 234, 23};

    Game game;

    game.start();


    return 0;
}


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rectangle");

    //Green
    sf::RectangleShape rectangleG(sf::Vector2f(20, 200));
    rectangleG.setFillColor(sf::Color::Green);
    rectangleG.setPosition(300, 250);

    //Red
    sf::RectangleShape rectangleR(sf::Vector2f(20, 200));
    rectangleR.setFillColor(sf::Color::Red);
    rectangleR.setPosition(400, 250);

    //Blue
    sf::RectangleShape rectangleB(sf::Vector2f(20, 200));
    rectangleB.setFillColor(sf::Color::Blue);
    rectangleB.setPosition(500, 250);





    bool movingUpR = true;
    bool movingUpG = true;
    bool movingUpB = true;
    float yPosG = rectangleG.getPosition().y;
    float yPosR = rectangleR.getPosition().y;
    float yPosB = rectangleB.getPosition().y;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move the rectangle up and down
        if (movingUpR)
        {
            yPosR -= 0.05f;
            if (yPosR < 0)
                movingUpR = false;
        }
        else
        {
            yPosR += 0.05f;
            if (yPosR > 400)
                movingUpR = true;
        }

        if (movingUpG)
        {
            yPosG -= 0.10f;
            if (yPosG < 0)
                movingUpG = false;
        }
        else
        {
            yPosG += 0.10f;
            if (yPosG > 400)
                movingUpG = true;
        }

        if (movingUpB)
        {
            yPosB -= 0.15f;
            if (yPosB < 0)
                movingUpB = false;
        }
        else
        {
            yPosB += 0.15f;
            if (yPosB > 400)
                movingUpB = true;
        }

        rectangleR.setPosition(rectangleR.getPosition().x, yPosR);
        rectangleG.setPosition(rectangleG.getPosition().x, yPosG);
        rectangleB.setPosition(rectangleB.getPosition().x, yPosB);

        window.clear();
        window.draw(rectangleG);
        window.draw(rectangleR);
        window.draw(rectangleB);
        window.display();
    }

    return 0;
}
