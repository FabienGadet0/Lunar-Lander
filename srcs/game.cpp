#include "game.h"

Game::Game(sf::RenderWindow &win) : _win(win) {

}

Game::~Game() {}

void Game::event()
{
    sf::Event event;
    while (_win.pollEvent(event))
    {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _win.close();
    // _ship.event();
    }
}

void Game::display()
{
    _win.draw(_ship.getSprite());
    _win.display();
}

void Game::update()
{
    _ship.debug();
    _ship.update();
}

void Game::run()
{
    while (_win.isOpen())
        {
            this->event();

            _win.clear();
            this->update();
            this->display();
        }
}