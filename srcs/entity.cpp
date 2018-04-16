#include "entity.h"

Entity::Entity() :  _fuel(100) , _speed(0)
{
}

void Entity::update() {}

void Entity::debug() 
{
}

void Entity::updatePos()
{
    Collider::_c = _sprite.getGlobalBounds();
}

void Entity::draw(sf::RenderWindow &w)
{
    w.draw(getSprite());
}