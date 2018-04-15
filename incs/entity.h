#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "define.h"
#include <cmath>
#include <string>

class Entity
{
public:

    Entity();
    ~Entity(){}

    virtual void update();
    virtual void debug();

    sf::Sprite getSprite() const {return _sprite;}
    sf::Vector2f getPos() const {return _sprite.getPosition();}
    float getSpeed(){return _speed;}

protected:
    sf::Sprite _sprite;
    sf::Texture _tex;
    float _speed;
    float _direction;   
};


#endif