#include "spaceship.h"

SpaceShip::SpaceShip() :  Entity::Entity()
{
    _tex.loadFromFile("./assets/spaceship.png");
    _sprite.setTexture(_tex);
    _sprite.setPosition(WINX / 2, WINY / 3); 
    _sprite.setRotation(-90.f);
    Collider::init(_sprite.getGlobalBounds(), SPACESHIP);
}

SpaceShip::~SpaceShip() {}

void SpaceShip::event()
{   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && _fuel > 0 && _speed < 5)
        _speed += SHIPSPEED;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        _sprite.rotate(- (TURNRATE * 10));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        _sprite.rotate(TURNRATE * 10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && _speed > 0 && _fuel > 0)
        _speed -= SHIPSPEED / 5;
}

void SpaceShip::set_angle_and_pos()
{
    _sprite.move(std::cos(3.14159265 * _sprite.getRotation() / 180.f) * _speed,
    (std::sin(3.14159265 * _sprite.getRotation() / 180.f) * _speed ) + GRAVITY);
}

void SpaceShip::regulate_fuel_and_speed()
{
    if (_speed > 0 && _fuel > 0)
        _fuel -= (_speed / 100 );
    if (_speed <= 0)
        _speed = 0;
    if (_fuel <= 0)
        _speed -= 0.0001;
}

void SpaceShip::collider(std::vector<sf::VertexArray>)
{
    
}


void SpaceShip::update()
{
    event();
    // debug();
    updatePos();
    regulate_fuel_and_speed();
    set_angle_and_pos();
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
