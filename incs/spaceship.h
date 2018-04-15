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


    void update();
    void debug();

protected:
    float _fuel;

};


#endif