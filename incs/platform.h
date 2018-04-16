#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <SFML/Graphics.hpp>

#include "entity.h"
#include "define.h"


class Platform : public Entity
{
public:

    Platform(){}
    Platform(const sf::Vector2f &);
    ~Platform();
    virtual void draw(sf::RenderWindow &);
    virtual void update() {}
    virtual void updatePos(){}
    virtual void debug(){}
    
    void setPos(const sf::Vector2f &);

protected:
    sf::RectangleShape _plat;
};


#endif