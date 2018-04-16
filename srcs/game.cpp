#include "game.h"

Game::Game(sf::RenderWindow &win) : _win(win)
{
    _mainView.setSize(sf::Vector2f(WINX, WINY));
    _mainView.setCenter(sf::Vector2f(WINX / 2, WINY / 2));
    _scene.push_back(new SpaceShip());
    createGround();
}

Game::~Game() {}

void Game::createGround()
{
    sf::VertexArray line(sf::Lines, 2);
    line[1] = sf::Vertex(sf::Vector2f(- WINX, WINY));
    for(int i = - WINX; i != WINX; ++i)
    {
        line[0] = line[1];
        line[1] = sf::Vertex(sf::Vector2f(100 * i,
         WINY - (rand() % 500)));
        _ground.push_back(line);
    }
}

void Game::event()
{
    sf::Event event;
    while (_win.pollEvent(event))
    {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _win.close();
    }
}

void Game::draw_and_display()
{
    for (auto it = _scene.begin() ; it != _scene.end(); ++it)
        _win.draw ((*it)->getSprite());
    for (auto it2 = _ground.begin() ; it2 != _ground.end(); ++it2)
        _win.draw(*it2);
   
    _win.setView(_mainView);
    _win.display();
}

void Game::moveView()
{
    _mainView.setCenter(_scene[0]->getPos().x, WINY / 2);

    // if (_scene[0].getPos().x > _mainView.getCenter().x * 1.5)
    //     _mainView.move(_scene[0].getSpeed() * 2, 0);
}

void Game::update()
{
    for (auto it = _scene.begin() ; it != _scene.end(); ++it)
        (*it)->update();
    debug();
    moveView();
}

void Game::run()
{
    while (_win.isOpen())
        {
            this->event();
            this->update();
            _win.clear();
            this->draw_and_display();
        }
}

void Game::debug()
{
    _scene[0]->debug();
    std::cout << "Camera pos x : " << 
    std::to_string(_mainView.getCenter().x) << " y : " << 
    std::to_string(_mainView.getCenter().y) << std::endl;
}