#include "ui.h"

Ui::Ui()
{
    if (!_font.loadFromFile("./font/Symtext.ttf"))
        std::cout << "error Loading Font" << std::endl;
    _text.setFont(_font);
    _text.setCharacterSize(UISIZE);
    _text.setColor(UICOLOR);
    _information.setFont(_font);
    _information.setCharacterSize(30);
    _information.setColor(sf::Color::Red);    
    setText("NOT SET");
    _information.setString("YOU LOOSE");
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

void Ui::drawInformation(sf::RenderWindow &w, sf::View &v, const int &id)
{
    _information.setPosition(sf::Vector2f(v.getCenter().x - ((UISIZE * _text.getString().getSize() / 3)) , v.getCenter().y - 200));
    if (id == 2)
    {
        _information.setColor(sf::Color::Red);
        _information.setString("Collision, you failed");
    }    
    else if (id == 1)
    {
        _information.setColor(sf::Color::Green);
        _information.setString("You reached a platform , congratulation !");
    }    
    else if (id == 3)
    {
        _information.setColor(sf::Color::Red);
        _information.setString("Pause");
    }    
    w.draw(_information);
}

Ui::~Ui()
{

}
