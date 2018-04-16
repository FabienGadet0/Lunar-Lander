#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "define.h"
#include "ui.h"
#include "ground.h"
#include "platform.h"
#include <string>

typedef struct Ground{
    sf::VertexArray line;
    Collider _c;
}              Ground;

class Game
{
public:

    Game(sf::RenderWindow &);
    ~Game();
    void event();
    void update();
    void draw_and_display();
    void moveView_and_ui();
    void run();
    void debug();
    void createGround_and_platforms();
    void debug_collision();

protected:
    sf::RenderWindow &_win;
    std::vector<Entity *> _scene;
    SpaceShip _ship;
    sf::Texture _tex;
    sf::View _mainView;
    std::vector<Ground> _ground;
    std::vector<sf::RectangleShape> _scene_debug;
    Ui _ui;
    bool _itsOver;
};


#endif 