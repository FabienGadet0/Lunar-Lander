#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "define.h"
#include "collider.h"
#include <cmath>
#include <string>

class Entity : public Collider
{
public:

    Entity();
    ~Entity(){}

    virtual void update();
    virtual void debug();
    void collider(){}
    virtual void draw(sf::RenderWindow &);
    virtual void updatePos();

    sf::Sprite getSprite() const {return _sprite;}
    sf::Vector2f getPos() const {return _sprite.getPosition();}
    float getFuel() const {return _fuel;}
    float getSpeed() const {return _speed;}

protected:
    sf::Sprite _sprite;
    sf::Texture _tex;
    float _speed;
    float _fuel;
    float _direction;   
};


#endif