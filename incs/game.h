#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "define.h"

class Game
{
public:

    Game(sf::RenderWindow &);
    ~Game();
    void event();
    void update();
    void display();
    void run();

protected:
    sf::RenderWindow &_win;
    SpaceShip _ship;
    sf::Texture _tex;
};


#endif 