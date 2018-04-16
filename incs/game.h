#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "define.h"
#include <string>

class Game
{
public:

    Game(sf::RenderWindow &);
    ~Game();
    void event();
    void update();
    void draw_and_display();
    void moveView();
    void run();
    void debug();
    void createGround();

protected:
    sf::RenderWindow &_win;
    std::vector<Entity *> _scene;
    SpaceShip _ship;
    sf::Texture _tex;
    sf::View _mainView;
    std::vector<sf::VertexArray> _ground;

};


#endif 