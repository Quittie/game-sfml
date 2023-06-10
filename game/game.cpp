#include "game.h"
#include "barricadem.h"
#include "player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <valarray>

Game::Game() {
    std::cout << "Let's start the game!" << std::endl;
    this->variablesInit();
    this->screen = new Immoveable("screen.png");
    this->pitch = new Immoveable("trawka.png");
    this->windowInit();
    this->playerInit();
    this->barricadesInit();
    this->ballInit();
    this->gate = new Immoveable("bramka.png",{1820, 390},{100, 300});
    this->hearts = new ImmoveableCounter("heart.png",{0,0},{100,100}, 3);
    this->attempts = new ImmoveableCounter("ball3.png",{400,0},{100,100}, 3);
    this->goals = new CounterWithText("ball2.png", {800, 0}, {100, 100}, 0);
    this->time = new CounterWithText("clock.png", {1700, 0}, {100, 100}, 20);
    this->penaltyArea = new Immoveable({1720, 390},{200, 300});
    this->playerArea = new Immoveable({0, 0},{600, 1080});
    this->goalkeeper = new Goalkeeper({1400, 500}, {100, 100}, {}, 60, "player.png");
    createResults();
    loadMusic();

}

Game::~Game()
{
    delete this->window;
}

void Game::update(bool &keyPressed)
{
    elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= 1) {
        this->goalkeeper->update(this->penaltyArea->getSize(), penaltyArea->getSprite().getPosition());
        this->time->decreaseCounter();
        clock.restart();
    }
    if(reset) {
        resetGame();
        reset = false;
    }
    this->pollEvents();
    this->player->update(this->window);
    for (const auto &barricade: this->barricades) {
        barricade->update(this->window);
    }
    this->updateCollision(keyPressed);
    this->ball->update(this->window);
    if(attempts->getCounter() == -1 || this->time->getCounter() < 0) {
        hearts->decreaseCounter();
        reset = true;
        if(hearts->getCounter() == 0) {
            deathscreen = true;
        }
    }
}

void Game::resetGame() {
    this->ball->reset();
    this->player->reset();
    this->attempts->reset();
    this->time->reset();
}

void Game::render()
{
    this->window->clear();
    if(deathscreen == false)
    {
        loadMusic();
        this->pitch->render(this->window);
        this->player->render(this->window);

        for (const auto &barricade: this->barricades) {
            barricade->render(this ->window);
        }
        this->ball->render(this->window);
        this->gate->render(this->window);
        this->hearts->render(this->window);
        this->attempts->render(this->window);
        this->goals->render(this->window);
        if(add==true&&goals->getCounter()==3)
        {
            increaseLevel1();
            add = false;

        }
        this->time->render(this->window);
        this->penaltyArea->render(this->window);
        this->playerArea->render(this->window);
        this->goalkeeper->render(this->window);
    }
    else
    {
        stopMusic();
        this->screen->render(this->window);
        showResults();
    }
    this->window->display();
}

void Game::variablesInit()
{
    this->window = nullptr;
}

void Game::windowInit()
{
    sf::VideoMode desktopM = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(desktopM, "Soccer Challenge 2k23", sf::Style::Titlebar | sf::Style::Close /*| sf::Style::Fullscreen*/);
    this->window->setFramerateLimit(60);
}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while(this->window->pollEvent(this->sfmlEvent)) {
        switch(this->sfmlEvent.type){
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::playerInit() {
    this->player = new Player({200, 540}, {100, 100}, "player.png", 10);
}

void Game::barricadesInit() {
    Barricade b1({700, 50}, {40, 200}, {103, 35, 0}, 3, true);
    Barricade b2({800, 524}, {40, 150}, {103, 35, 0}, 2, false);
    Barricade b3({900, 124}, {40, 300}, {103, 35, 0}, 2, true);
    Barricade b4({1000, 624}, {40, 100}, {103, 35, 0}, 5, false);
    Barricade b5({1100, 524}, {40, 250}, {103, 35, 0}, 2, true);
    Barricade b6({1200, 563}, {40, 220}, {103, 35, 0}, 4, false);
    Barricade b7({1300, 600}, {40, 420}, {103, 35, 0}, 2, true);
    Barricade b8({1400, 500}, {40, 150}, {103, 35, 0}, 2, true);
    barricades.push_back(std::make_unique<Barricade>(b1));
    barricades.push_back(std::make_unique<Barricade>(b2));
    barricades.push_back(std::make_unique<Barricade>(b3));
    barricades.push_back(std::make_unique<Barricade>(b4));
    barricades.push_back(std::make_unique<Barricade>(b5));
    barricades.push_back(std::make_unique<Barricade>(b6));
    barricades.push_back(std::make_unique<Barricade>(b7));
    barricades.push_back(std::make_unique<Barricade>(b8));
}

void Game::ballInit() {
    this->ball = new Ball({400,540}, {1,1}, "ball.png",0);
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
            std::cout << "Piłka wpadła do bramki!" << std::endl;
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

    score.setString(std::to_string(goals->getCounter()));
    auto font = new sf::Font;
    if (!font->loadFromFile("arial.ttf")) {
        std::cout << "Error :( " << std::endl;
        // Error handling if the font fails to load
    }
    score.setFont(*font);
    score.setPosition(900, 500);
    score.setCharacterSize(100);
    score.setFillColor(sf::Color::Cyan);
}

void Game::showResults()
{
    score.setString(std::to_string(goals->getCounter()));
    this->window->draw(score);

}

void Game::loadMusic()
{
    if (!music.openFromFile("soccermusic.wav")) {
        std::cout << "Asd" << std::endl;
        // Obsługa błędu - nie można załadować pliku
    }
    music.setLoop(true);
    music.setVolume(100);
    music.play();

}

void Game::stopMusic()
{
    music.stop();
}

void Game::increaseLevel1()
{
    Barricade b9({750, 50}, {40, 210}, {103, 35, 0}, 3, false);
    Barricade b10({550, 524}, {40, 170}, {103, 35, 0}, 2, false);
    Barricade b11({370, 124}, {40, 350}, {103, 35, 0}, 2, true);

    barricades.push_back(std::make_unique<Barricade>(b9));
    barricades.push_back(std::make_unique<Barricade>(b10));
    barricades.push_back(std::make_unique<Barricade>(b11));

}
void Game::increaseLevel2()
{

}
