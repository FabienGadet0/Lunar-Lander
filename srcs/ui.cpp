#include "ui.h"

Ui::Ui()
{
    if (!_font.loadFromFile("./font/Symtext.ttf"))
        std::cout << "error Loading Font" << std::endl;
    _text.setFont(_font);
    _text.setCharacterSize(UISIZE);
    _text.setColor(UICOLOR);
    _loose.setFont(_font);
    _loose.setCharacterSize(80);
    _loose.setColor(sf::Color::Red);    
    setText("NOT SET");
    _loose.setString("YOU LOOSE");
    setPosition(0,0);
}

void Ui::setText(const std::string &s)
{
    _text.setString(s);
}

void Ui::setPosition(const float &x, const float &y)
{
    _text.setPosition(x,y);
}

void Ui::draw(sf::RenderWindow &w)
{
    w.draw(_text);
}

void Ui::getInformation(Entity *s)
{
    setText("Speed : " + std::to_string(s->getSpeed())
     + "\nfuel :" + std::to_string(s->getFuel()) + "\nGravity : "
     + std::to_string(GRAVITY));
}

void Ui::move(const float &x, const float &y)
{
    _text.move(x, y);
}

void Ui::youLoose(sf::RenderWindow &w, sf::View &v)
{
    _loose.setPosition(sf::Vector2f(v.getCenter().x , v.getCenter().y - 200));
    w.draw(_loose);
}

Ui::~Ui()
{

}
