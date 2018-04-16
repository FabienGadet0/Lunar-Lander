#include "entity.h"

Entity::Entity()
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