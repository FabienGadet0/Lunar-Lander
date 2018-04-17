#ifndef UI_H_
#define UI_H_

#include <SFML/Graphics.hpp>
#include "define.h"
#include "spaceship.h"
#include <string>

class Ui
{
public:

    Ui();
    ~Ui();

    void setText(const std::string &);
    void setPosition(const float &, const float &);
    void draw(sf::RenderWindow &);
    void getInformation(Entity *);
    void move(const float &, const float &);
    void drawInformation(sf::RenderWindow &, sf::View &, const int &);

protected:
    sf::Font _font;
    sf::Text _text;
    sf::Text _information;
};


#endif 