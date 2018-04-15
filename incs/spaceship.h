#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "define.h"
#include <cmath>

class SpaceShip
{
public:

    SpaceShip();
    ~SpaceShip();
    void event();
    void update();
    void debug();

    sf::Sprite getSprite() const {return _sprite;}
    sf::Vector2f getPos() const {return _pos;}

protected:
    sf::Sprite _sprite;
    sf::Texture _tex;
    sf::Vector2f _pos;

    float _speed;
    float _direction;

    float _fuel;
};


#endif