#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINX, WINY), WINDOWNAME);
    window.setFramerateLimit(60);
    Game game(window);
    game.run();
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.display();
    // }

    return 0;
}