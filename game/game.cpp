#include "game.h"
#include "barricadem.h"
#include "player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <valarray>
#include <string>

Game::Game() {
    std::cout << "Let's start the game!" << std::endl;
    this->screen = new Immoveable("gameover.png", {0, 0}, {1920, 1050}); //"screen" object of type "Immoveable" initialised - it will appear once the game is finished
    this->pitch = new Immoveable("grass.png", {0, 0}, {1920, 1050}); //"pitch" object of type "Immoveable" initialised
    this->windowInit(); //game window initialised
    this->playerInit(); //player initialised
    this->barricadesInit(); //barricades initialised
    this->ballInit(); //ball initialised
    this->gate = new Immoveable("gate.png",{1820, 390},{100, 300}); //"pitch" object of type "Immoveable" initialised with given parameters
    this->hearts = new ImmoveableCounter("heart.png",{0,0},{100,100}, 3); //"hearts" object of type "ImmoveableCounter" initialised with given parameters
    this->attempts = new ImmoveableCounter("ball3.png",{400,0},{100,100}, 3); //"attempts" object of type "ImmoveableCounter" initialised with given parameters
    this->goals = new CounterWithText("ball2.png", {800, 0}, {100, 100}, 0); //"goals" object of type "CounterWithText" initialised with given parameters
    this->time = new CounterWithText("clock.png", {1700, 0}, {100, 100}, 20); //"attempts" object of type "CounterWithText" initialised with given parameters
    this->penaltyArea = new Immoveable({1720, 390},{200, 300}); //"penaltyArea" object of type "Immoveable" initialised with given parameters
    this->playerArea = new Immoveable({0, 0},{600, 1080}); //"playerArea" object of type "Immoveable" initialised with given parameters
    this->goalkeeper = new Goalkeeper({1400, 500}, {100, 100}, {}, 60, "goalkeeper.png"); //"goalkeeper" object of type "Goalkeeper" initialised with given parameters
    createSign(); //creates a sign: "Press any key to continue the game. Your final score: "
    createResults(); //creates a sign with current score
    createFinalSign(); //creates a sign which will be shown once the game is finished
    loadMusic(); //loads music from a specified file and starts playing it when Game object created
    loadTrumpet(); //loads end music from a specified file
}

Game::~Game()
{
    delete this->window; // Game class destructor
}

void Game::update(bool &keyPressed) //updates game, keyPressed prevents player from losing chances by holding the space bar
{
    elapsed = clock.getElapsedTime(); //takes time parameters since the last restart of the clock
    if (elapsed.asSeconds() >= 1) //converts time into seconds and compares with 1 second to handle timer
    {
        this->goalkeeper->update(this->penaltyArea->getSize(), penaltyArea->getSprite().getPosition()); //updates goalkeeper every second
        this->time->decreaseCounter(); //decreases time of the round
        clock.restart(); //restarts the clock
    }
    if(reset) //checks if object positions need to be reset
    {
        resetGame(); //resets objects
        reset = false; //change the value of the flag
    }
    this->pollEvents(); //checks if game window needs to be closed
    this->player->update(this->window); //updates current state of the player
    this->player->animate(elapsed); //animates the player in respect to elapsed time
    for (const auto &barricade: this->barricades)//traverses the vector of barricades
    {
        barricade->update(this->window); //updates current state of the barricades
    }
    this->updateCollision(keyPressed); //handles collisions beetween objects
    this->ball->update(this->window); //updates ball state
    if(attempts->getCounter() == -1 || this->time->getCounter() < 0) //checks if player is out of chances of time
    {
        hearts->decreaseCounter(); //decreases number of hearts by one
        reset = true; //switches the flag to true
        if(hearts->getCounter() == 0) //checks if the player is out of hearts
        {
            deathscreen = true; //switches the flag to true in order to display the deathscreen
        }
    }
}

void Game::resetGame() //resets the game
{
    this->ball->reset();
    this->player->reset();
    this->attempts->reset();
    this->time->reset();
}

void Game::render() //renders the game
{

    this->window->clear(); //clears window
    if(deathscreen == false) //checks if deathscreen should appear
    {
        this->pitch->render(this->window);
        this->player->render(this->window);

        for (const auto &barricade: this->barricades) {
            barricade->render(this ->window);
        }
        this->ball->render(this->window);
        this->goalkeeper->render(this->window);
        this->gate->render(this->window);
        this->hearts->render(this->window);
        this->attempts->render(this->window);
        this->goals->render(this->window);
        if(add1==true&&goals->getCounter()==3) //checks if the player scored 3
        {
            increaseLevel1(); //increases difficulty level
            add1 = false; //changes the flag value in order to increase level only once

        }
        if(add2==true&&goals->getCounter()==5) //checks if the player scored 5
        {
            increaseLevel2(); //increases difficulty level
            add2 = false; //changes the flag value in order to increase level only once
        }
        this->time->render(this->window);
        this->penaltyArea->render(this->window);
        this->playerArea->render(this->window);
        if(sfmlEvent.key.code == sf::Keyboard::Enter) //checks if enter is pressed
        {
            showSign(); //shows sign "Press any key to continue the game. Your final score: "
            showResults(); //shows results
        }


    }
    else //if deathscreen should appear
    {
        stopMusic(); //stops playing musisc
        this->screen->render(this->window); //renders deathscreen
        showResults(); //shows final results
        showFinalSign(); //shows final sign
        if(play) //checks if final music should be played
        {
            trumpet.play(); //plays final music
            play = false; //changes the flag value in order to play music only once
        }
    }

    this->window->display(); //displays window game
    }

void Game::windowInit() //initialises game window
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode(); //gets information about screen height and width
    this->window = new sf::RenderWindow(desktopM, "Soccer Challenge 2k23", sf::Style::Titlebar | sf::Style::Close); //initialises a window with a given name, screen dimensions and styles
    this->window->setFramerateLimit(60); //sets max framerate to 60
}

bool Game::running() const //checks if window is open
{
    return this->window->isOpen();
}

void Game::pollEvents() //handles events
{
    while(this->window->pollEvent(this->sfmlEvent)) {
        switch(this->sfmlEvent.type){
        case sf::Event::Closed:
            this->window->close(); //closes window when "close" is pressed
            break;
        case sf::Event::KeyPressed:
            if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close(); //closes window when "escape" is pressed
            break;
        default:
            break;
        }
    }
}

void Game::playerInit()
{
    this->player = new Player({200, 540}, {100, 100}, "pngwing.png", 10); //initialises player with given parameters
}

void Game::barricadesInit()
{
    Barricade b1({900, 50}, {40, 100}, {103, 35, 0}, 3, true); //initialises 3 barricades with given parameters
    Barricade b2({800, 500}, {40, 100}, {103, 35, 0}, 2, false);
    Barricade b3({1100, 150}, {40, 100}, {103, 35, 0}, 4, true);
    Barricade b4({1200, 400}, {40, 100}, {103, 35, 0}, 3.5, true);
    Barricade b5({1300, 350}, {40, 100}, {103, 35, 0}, 2, true);
    Barricade b6({1000, 250}, {40, 100}, {103, 35, 0}, 2.5, true);

    barricades.push_back(std::make_unique<Barricade>(b1)); //pushes back 3 objects to vector of unique pointers
    barricades.push_back(std::make_unique<Barricade>(b2));
    barricades.push_back(std::make_unique<Barricade>(b3));
    barricades.push_back(std::make_unique<Barricade>(b4));
    barricades.push_back(std::make_unique<Barricade>(b5));
    barricades.push_back(std::make_unique<Barricade>(b6));

}

void Game::ballInit()
{
    this->ball = new Ball({400,540}, {1,1}, "ball.png",0); //initialises a Ball object with given parameters
}

void Game::updateCollision(bool& keyPressed) {

    // barricades - ball
    for (const auto &barricade: this->barricades) {
        if(this->ball->getShape().getGlobalBounds().intersects(barricade->getRectangleShape().getGlobalBounds())) {
            sf::Vector2f ballCenter = ball->getShape().getPosition() + sf::Vector2f(ball->getShape().getRadius(), ball->getShape().getRadius());
            sf::Vector2f rectangleCenter = barricade->getRectangleShape().getPosition() + 0.5f * barricade->getRectangleShape().getSize();

            // Obliczenie wektora normalnego do powierzchni prostokąta
            sf::Vector2f normalVector = ballCenter - rectangleCenter;

            // Normalizacja wektora normalnego
            float length = std::sqrt(normalVector.x * normalVector.x + normalVector.y * normalVector.y);
            normalVector /= length;

            // Obliczenie kierunku odbicia
            sf::Vector2f reflectionDirection = 2.f * (ball->getBallVelocity().x * normalVector.x + ball->getBallVelocity().y * normalVector.y) * normalVector - ball->getBallVelocity();

            ball->kick(reflectionDirection.x,reflectionDirection.y);
        }
    }

    // ball - player
    if(this->ball->getShape().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyPressed) {
            float deltaX = ball->getShape().getPosition().x - this->player->getSprite().getPosition().x;
            float deltaY = ball->getShape().getPosition().y - this->player->getSprite().getPosition().y;
            float kickAngleRad = -std::atan2(deltaY, deltaX);
            float velocityX = 20 * std::cos(kickAngleRad);
            float velocityY = -20 * std::sin(kickAngleRad);
            ball->kick(velocityX, velocityY);
            this->attempts->decreaseCounter();
            keyPressed = false;
        }
    } else {
        keyPressed = true;
    }

    // ball - gate
    sf::FloatRect ballBounds = ball->getShape().getGlobalBounds();
    sf::FloatRect gateBounds = gate->getSprite().getGlobalBounds();
    if (ballBounds.top + ballBounds.height >= gateBounds.top &&
        ballBounds.top <= gateBounds.top + gateBounds.height) {
        if (ballBounds.left <= gateBounds.left + gateBounds.width &&
            ballBounds.left + ballBounds.width >= gateBounds.left) {
            this->goals->increaseCounter();
            std::cout << "Goaaaal!" << std::endl;
                    reset = true;
        }
    }

    // player - player area
    checkPlayerArea();

    // ball - goalkeeper
    if(this->ball->getShape().getGlobalBounds().intersects(goalkeeper->getRectangleShape().getGlobalBounds())) {
        sf::Vector2f ballCenter = ball->getShape().getPosition() + sf::Vector2f(ball->getShape().getRadius(), ball->getShape().getRadius());
        sf::Vector2f rectangleCenter = goalkeeper->getRectangleShape().getPosition() + 0.5f * goalkeeper->getRectangleShape().getSize();

        // Obliczenie wektora normalnego do powierzchni prostokąta
        sf::Vector2f normalVector = ballCenter - rectangleCenter;

        // Normalizacja wektora normalnego
        float length = std::sqrt(normalVector.x * normalVector.x + normalVector.y * normalVector.y);
        normalVector /= length;

        // Obliczenie kierunku odbicia
        sf::Vector2f reflectionDirection = 2.f * (ball->getBallVelocity().x * normalVector.x + ball->getBallVelocity().y * normalVector.y) * normalVector - ball->getBallVelocity();

        ball->kick(reflectionDirection.x,reflectionDirection.y);
    }

}

void Game::checkPlayerArea() {
    float playerX = player->getSprite().getPosition().x;
    float maximumX = playerArea->getSize()[0];

    if(playerX > maximumX) {
        player->updatePosition(maximumX, player->getSprite().getPosition().y);
    }
}

void Game::createResults()
{
    auto font = new sf::Font;
    if (!font->loadFromFile("ourland.ttf")) {
        std::cout << "Error :( " << std::endl;
        // Error handling if the font fails to load
    }
    score.setFont(*font);
    score.setPosition(900, 720);
    score.setCharacterSize(100);
    score.setFillColor(sf::Color::Black);
}

void Game::showResults() //shows final results
{
    score.setString(std::to_string(goals->getCounter())); //assigns a string converted from the goal counter to an object of type sf::Text
    this->window->draw(score); //displays this object
}

void Game::showFinalSign()
{
    this->window->draw(finalSign);
}

void Game::createFinalSign()
{
    std::string sign = "\tYour final score is: ";
    finalSign.setString(sign);
    auto font = new sf::Font;
    if (!font->loadFromFile("ourland.ttf")) {
        std::cout << "Error :( " << std::endl;
        // Error handling if the font fails to load
    }
    finalSign.setFont(*font);
    finalSign.setPosition(350, 600);
    finalSign.setCharacterSize(100);
    finalSign.setFillColor(sf::Color::Black);
}


void Game::createSign()
{
    std::string signS =  "\t     Press any key \n  to continue the game \n \n   Your current score: ";
    sign.setString(signS);
    auto font = new sf::Font;
    if (!font->loadFromFile("ourland.ttf")) {
        std::cout << "Error :( " << std::endl;
        // Error handling if the font fails to load
    }
    sign.setFont(*font);
    sign.setPosition(350, 200);
    sign.setCharacterSize(100);
    sign.setFillColor(sf::Color::Black);
}

void Game::showSign()
{
    this->window->draw(sign);
}


void Game::loadMusic()
{
    if (!music.openFromFile("soccermusic.wav")) {
        std::cout << "Asd" << std::endl;
        // Obsługa błędu - nie można załadować pliku
    }
    music.play();
    music.setLoop(true);
    music.setVolume(10);


}

void Game::loadTrumpet()
{
    if (!trumpet.openFromFile("trumpet.wav")) {
        std::cout << "Asd" << std::endl;
        // Obsługa błędu - nie można załadować pliku
    }
}

void Game::stopMusic()
{
    music.stop();
}

void Game::increaseLevel1()
{
    Barricade b1({850, 100}, {40, 75}, {103, 35, 0}, 3, false);
    Barricade b2({950, 550}, {40, 75}, {103, 35, 0}, 2, false);
    Barricade b3({1050, 350}, {40, 75}, {103, 35, 0}, 2, true);
    Barricade b4({1150, 100}, {40, 75}, {103, 35, 0}, 3, false);
    Barricade b5({1250, 550}, {40, 75}, {103, 35, 0}, 2, false);
    Barricade b6({1350, 350}, {40, 75}, {103, 35, 0}, 2, true);



    barricades.push_back(std::make_unique<Barricade>(b1));
    barricades.push_back(std::make_unique<Barricade>(b2));
    barricades.push_back(std::make_unique<Barricade>(b3));
    barricades.push_back(std::make_unique<Barricade>(b4));
    barricades.push_back(std::make_unique<Barricade>(b5));
    barricades.push_back(std::make_unique<Barricade>(b6));

}
void Game::increaseLevel2()
{
    for(auto &bar : barricades)
    {
        for(int i=0; i < 5; i++)
        {
            bar->speedUp();
        }

    }
}
