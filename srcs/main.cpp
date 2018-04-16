#include <SFML/Graphics.hpp>
#include "game.h"


int main()
{
    srand(time(NULL)); 
    sf::RenderWindow window(sf::VideoMode(WINX, WINY), WINDOWNAME);
    window.setFramerateLimit(60);
    Game game(window);
    game.run();

    return 0;
}