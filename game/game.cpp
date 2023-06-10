#include "game.h"
#include "barricadem.h"
#include "player.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <valarray>

Game::Game() {
    std::cout << "Let's start the game!" << std::endl;
    this->variablesInit();
    this->pitch = new Immoveable("trawka.png");
    this->windowInit();
    this->playerInit();
    this->barricadesInit();
    this->ballInit();
    this->gate = new Immoveable("bramka.png",{1820, 390},{100, 300});
    this->hearts = new ImmoveableCounter("serce.png"," serce.png",{0,0},{100,100}, 3);
    //        this->attempts = new ImmoveableCounter("../Assets/serce.png","../Assets/serce.png",{400,0},{100,100}, 3);
    //        this->goals = new ImmoveableCounter("../Assets/serce.png","../Assets/serce.png",{800,0},{100,100}, 3);
}

Game::~Game()
{
    delete this->window;
}

void Game::update(float dt)
{
    //    if(attempts->getCounter() == 3) {
    //        hearts->setCounter(hearts->getCounter()-1);
    //        if(hearts->getCounter() == 0) {
    //            // TODO: gameOver();
    //        }
    //    }
    if(reset) {
        resetGame();
        reset = false;
    }
    this->pollEvents();
    this->player->update(this->window);
    for (const auto &barricade: this->barricades) {
        barricade->update(this->window);
    }
    this->updateCollision();
    this->ball->update(this->window);
}

void Game::resetGame() {
    this->ball->reset();
    this->player->reset();
}

void Game::render()
{
    this->window->clear();
    this->pitch->render(this->window);
    this->player->render(this->window);
    for (const auto &barricade: this->barricades) {
        barricade->render(this ->window);
    }
    this->ball->render(this->window);
    this->gate->render(this->window);
    this->hearts->render(this->window);
    //    this->attempts->render(this->window);
    //    this->goals->render(this->window);
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
    this->player = new Player({200, 540}, {50, 100}, "player.png", 10);
}

void Game::barricadesInit() {
    Barricade b1({700, 350}, {20, 100}, {103, 35, 0}, 2, true);
    Barricade b2({800, 524}, {20, 100}, {103, 35, 0}, 2, false);
    Barricade b3({900, 424}, {20, 100}, {103, 35, 0}, 2, true);
    Barricade b4({1000, 624}, {20, 100}, {103, 35, 0}, 2, false);
    Barricade b5({1100, 524}, {20, 100}, {103, 35, 0}, 2, true);
    Barricade b6({1200, 563}, {20, 100}, {103, 35, 0}, 2, false);
    Barricade b7({1300, 400}, {20, 100}, {103, 35, 0}, 2, true);
    Barricade b8({1400, 500}, {20, 100}, {103, 35, 0}, 2, true);
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

void Game::updateCollision() {

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
        this->ball->getShape().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
        float deltaX = ball->getShape().getPosition().x - this->player->getSprite().getPosition().x;
        float deltaY = ball->getShape().getPosition().y - this->player->getSprite().getPosition().y;
        float kickAngleRad = -std::atan2(deltaY, deltaX);
        float velocityX = 20 * std::cos(kickAngleRad);
        float velocityY = -20 * std::sin(kickAngleRad);
        ball->kick(velocityX, velocityY);
    }

    // Sprawdzenie kolizji piłki z bramką
    sf::FloatRect ballBounds = ball->getShape().getGlobalBounds();
    sf::FloatRect gateBounds = gate->getSprite().getGlobalBounds();

    // Sprawdzenie czy piłka przecina bramkę pod kątem pionowym
    if (ballBounds.top + ballBounds.height >= gateBounds.top &&
        ballBounds.top <= gateBounds.top + gateBounds.height) {
        // Sprawdzenie czy piłka przecina bramkę pod kątem poziomym
        if (ballBounds.left <= gateBounds.left + gateBounds.width &&
            ballBounds.left + ballBounds.width >= gateBounds.left) {
            // Piłka wpadła do bramki

            score++;
            std::cout << "Goal!!! Ypur current score: " << score << std::endl;
            reset = true;
        }
    }
}
