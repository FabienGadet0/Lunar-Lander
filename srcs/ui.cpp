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
    _win.setFont(_font);
    _win.setCharacterSize(80);
    _win.setColor(sf::Color::Green);    
    _win.setString("YOU WON");
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
    _loose.setPosition(sf::Vector2f(v.getCenter().x - ((UISIZE * _text.getString().getSize() / 3)) , v.getCenter().y - 200));
    w.draw(_loose);
}

void Ui::youWin(sf::RenderWindow &w, sf::View &v)
{
    _win.setPosition(sf::Vector2f(v.getCenter().x - ((UISIZE * _text.getString().getSize() / 3)) , v.getCenter().y - 200));
    w.draw(_win);
}

Ui::~Ui()
{

}
