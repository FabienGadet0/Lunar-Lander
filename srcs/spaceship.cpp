#include "spaceship.h"

SpaceShip::SpaceShip() :  Entity::Entity(), _fuel(50)
{
    _tex.loadFromFile("./assets/spaceship.png");
    _sprite.setTexture(_tex);
    _sprite.setScale(sf::Vector2f(0.1f, 0.1f));
    _sprite.setPosition(WINX / 2, WINY / 3); 
    _sprite.setRotation(-90.f);
}

SpaceShip::~SpaceShip() {}

void SpaceShip::event()
{   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            if (_fuel > 0)
               _speed += SHIPSPEED;
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            _sprite.rotate(- (TURNRATE * 10));
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            _sprite.rotate(TURNRATE * 10);
        }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            if (_speed > 0)
                _speed -= SHIPSPEED;
        }
}

void SpaceShip::set_angle_and_pos()
{
    _sprite.move(std::cos(3.14159265 * _sprite.getRotation() / 180.f) * _speed,
    (std::sin(3.14159265 * _sprite.getRotation() / 180.f) * _speed ) + GRAVITY);

}

void SpaceShip::update()
{
    event();
    if (_speed > 0)
        _fuel -= (_speed / 100 );
    set_angle_and_pos();
    if (_speed < 0)
        _speed = 0;
}

void SpaceShip::debug()
{
    std::cout << "speed : " << _speed << std::endl << "fuel :"
    << _fuel << std::endl <<  "pos : "  <<
    "---------------------" << std::endl;
        std::cout << "ship pos x : " << 
    std::to_string(getPos().x) << " y : " << 
    std::to_string(getPos().y) << std::endl;
}
