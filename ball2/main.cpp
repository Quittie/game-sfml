#include <SFML/Graphics.hpp>
#include <sstream>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Move Ball");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("grass.png"))
    {
        // Failed to load texture, handle the error
        return 1;
    }

    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile("ball.png"))
    {
        // Failed to load texture, handle the error
        return 1;
    }

    sf::Sprite ball(ballTexture);

    // Set the initial position of the ball to the middle of the window
    ball.setPosition(200, 300);

    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(window.getSize().x / backgroundSprite.getLocalBounds().width,
                              window.getSize().y / backgroundSprite.getLocalBounds().height);

    float speed = 1 / 5.f;
    sf::Vector2f velocity(0.f, 0.f);
    sf::Vector2f previousVelocity(0.f, 0.f);
    bool spacePressed = false;
    bool ballMoving = false;

    sf::Vector2f rectPosition(600.f, window.getSize().y / 2 - 25.f);
    sf::Vector2f rectSize(20.f, 150.f);
    float rectSpeed = 1 / 3.f;
    bool rectMovingUp = true;

    sf::Vector2f rect2Position(500.f, window.getSize().y / 2 - 25.f);
    sf::Vector2f rect2Size(20.f, 100.f);
    float rect2Speed = 1 / 4.f;
    bool rect2MovingUp = true;

    // Properties for the new rectangle
    sf::Vector2f rect3Position(400.f, window.getSize().y / 2 - 25.f);
    sf::Vector2f rect3Size(20.f, 200.f);
    float rect3Speed = 1 / 5.f;
    bool rect3MovingUp = true;

    sf::Vector2f rect4Position(780, 225);
    sf::Vector2f rect4Size(20.f, 150.f);

    sf::Vector2f spawnPosition(200, 300); // Spawning coordinates for the ball

    int score = 0;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // Failed to load font, handle the error
        return 1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10, 10);
    scoreText.setFillColor(sf::Color::Black); // Set the color to black

    sf::RectangleShape rectangle(rectSize);
    rectangle.setPosition(rectPosition);
    rectangle.setFillColor(sf::Color::White); // Set the color of the first rectangle

    sf::RectangleShape rectangle2(rect2Size);
    rectangle2.setPosition(rect2Position);
    rectangle2.setFillColor(sf::Color::White); // Set the color of the second rectangle

    sf::RectangleShape rectangle3(rect3Size);
    rectangle3.setPosition(rect3Position);
    rectangle3.setFillColor(sf::Color::White); // Set the color of the third rectangle

    sf::RectangleShape rectangle4(rect4Size);
    rectangle4.setPosition(rect4Position);
    rectangle4.setFillColor(sf::Color::Black); // Set the color of the fourth rectangle


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && ballMoving)
                {
                    if (!spacePressed)
                    {
                        spacePressed = true;
                        // Store the previous velocity before the spacebar was pressed
                        previousVelocity = velocity;
                    }
                }
            }
        }

        if (ball.getGlobalBounds().intersects(sf::FloatRect(rect4Position, rect4Size)))
        {
            // Increase the score by 1
            score += 1;

            // Update the score text
            std::stringstream ss;
            ss << "Score: " << score;
            scoreText.setString(ss.str());

            // Return the ball to the spawning coordinates
            ball.setPosition(spawnPosition);
            spacePressed = false; // Reset the spacePressed flag
            ballMoving = false;   // Stop the ball from moving
        }

        // Move the ball based on arrow key inputs or previous direction
        if (!spacePressed)
        {
            // Reset the velocity
            velocity = sf::Vector2f(0.f, 0.f);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ball.getPosition().y > 0)
            {
                velocity.y = -speed;
                ballMoving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && ball.getPosition().y + ball.getGlobalBounds().height < window.getSize().y)
            {
                velocity.y = speed;
                ballMoving = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && ball.getPosition().x > 0)
            {
                velocity.x = -speed;
                ballMoving = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && ball.getPosition().x + ball.getGlobalBounds().width < window.getSize().x)
            {
                velocity.x = speed;
                ballMoving = true;
            }
        }

        if (spacePressed)
        {
            // Move the ball unconditionally in the previous direction
            ball.move(previousVelocity);

            // Check if the ball reaches the sides of the window
            if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getGlobalBounds().width >= window.getSize().x)
                previousVelocity.x = -previousVelocity.x;
            if (ball.getPosition().y <= 0 || ball.getPosition().y + ball.getGlobalBounds().height >= window.getSize().y)
                previousVelocity.y = -previousVelocity.y;

            // Check for collision with the rectangles
            if (ball.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
            {
                previousVelocity.x = -previousVelocity.x; // Reverse the x-direction velocity
            }

            if (ball.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))
            {
                previousVelocity.x = -previousVelocity.x; // Reverse the x-direction velocity
            }

            if (ball.getGlobalBounds().intersects(rectangle3.getGlobalBounds()))
            {
                previousVelocity.x = -previousVelocity.x; // Reverse the x-direction velocity
            }
        }
        else
        {
            // Move the ball based on the current velocity
            ball.move(velocity);
        }

        if (rectMovingUp)
        {
            rectPosition.y -= rectSpeed;
            if (rectPosition.y <= 0)
            {
                rectPosition.y = 0;
                rectMovingUp = false;
            }
        }
        else
        {
            rectPosition.y += rectSpeed;
            if (rectPosition.y + rectSize.y >= window.getSize().y)
            {
                rectPosition.y = window.getSize().y - rectSize.y;
                rectMovingUp = true;
            }
        }

        if (rect2MovingUp)
        {
            rect2Position.y -= rect2Speed;
            if (rect2Position.y <= 0)
            {
                rect2Position.y = 0;
                rect2MovingUp = false;
            }
        }
        else
        {
            rect2Position.y += rect2Speed;
            if (rect2Position.y + rect2Size.y >= window.getSize().y)
            {
                rect2Position.y = window.getSize().y - rect2Size.y;
                rect2MovingUp = true;
            }
        }

        if (rect3MovingUp)
        {
            rect3Position.y -= rect3Speed;
            if (rect3Position.y <= 0)
            {
                rect3Position.y = 0;
                rect3MovingUp = false;
            }
        }
        else
        {
            rect3Position.y += rect3Speed;
            if (rect3Position.y + rect3Size.y >= window.getSize().y)
            {
                rect3Position.y = window.getSize().y - rect3Size.y;
                rect3MovingUp = true;
            }
        }

        rectangle.setPosition(rectPosition);
        rectangle2.setPosition(rect2Position);
        rectangle3.setPosition(rect3Position);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(ball);
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        scoreText.setFillColor(sf::Color::Black); // Set the score text color to black
        window.draw(scoreText); // Draw the score text after clearing the window
        window.display();
    }

    return 0;
}
