#include "platform.h"

Platform::Platform(const sf::Vector2f &x)
{
    _plat.setSize(PLATFORMSIZE);
    _plat.setFillColor(sf::Color::White);
    _plat.setPosition(x);
    _id = PLATFORM;
    _c = _plat.getGlobalBounds();
}

Platform::Platform()
{
    _plat.setSize(PLATFORMSIZE);
    _plat.setFillColor(sf::Color::White);
    _id = PLATFORM;
}

Platform::~Platform()
{

}

void Platform::update()
{

}

void Platform::setPos(const sf::Vector2f &p)
{
    _plat.setPosition(p);    
}

void Platform::draw(sf::RenderWindow &w)
{
    w.draw(_plat);
}
