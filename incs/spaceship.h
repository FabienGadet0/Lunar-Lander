#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>

#include "entity.h"
#include "define.h"


class SpaceShip : public Entity
{
public:

    SpaceShip();
    ~SpaceShip();
    void event();
    void set_angle_and_pos();
    void regulate_fuel_and_speed();
    void update();
    void debug();
    // virtual void draw(sf::RenderWindow &);
    virtual void collider(std::vector<sf::VertexArray>);

protected:
    float _fuel;

};


#endif