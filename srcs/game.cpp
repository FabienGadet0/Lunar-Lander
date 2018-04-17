#include "game.h"

Game::Game(sf::RenderWindow &win) : _win(win), _itsOver(false), _winn(false), _pause(false)
{
    _mainView.setSize(sf::Vector2f(WINX, WINY));
    _mainView.setCenter(sf::Vector2f(WINX / 2, WINY / 2));
    _scene.push_back(new SpaceShip());
    createGround_and_platforms();
}

Game::~Game() 
{
    _scene.clear();
}

void Game::createGround_and_platforms()
{
    int nb_platform = 0;
    Ground g;
    g.line.setPrimitiveType(sf::Lines);
    g.line.resize(2);
    g.line[1] = sf::Vertex(sf::Vector2f(- WINX, WINY));

    for(int i = - WINX; i != WINX; ++i)
    {

        g.line[0] = g.line[1];
        g.line[1] = sf::Vertex(sf::Vector2f(20 * i,
         WINY - (rand() % 400)));
        g._c.init(g.line.getBounds(), 1);
        _ground.push_back(g);

        if (g._c.getRekt().top < 700 && (rand() % 1000) > 990)
            _scene.push_back(
                new Platform(sf::Vector2f(g._c.getRekt().left ,g._c.getRekt().top - 10)));

        if (DEBUG)
        {
            sf::RectangleShape tmp;
            tmp.setOutlineThickness(1);
            tmp.setOutlineColor(sf::Color::Red);
            tmp.setFillColor(sf::Color::Black);
            g._c.setPos(g.line.getBounds().top);
            tmp.setSize(g._c.getSize());
            tmp.setPosition(g._c.getRekt().left, g._c.getRekt().top);
            _scene_debug.push_back(tmp);
        }
    }
}

void Game::event()
{
    sf::Event event;
    while (_win.pollEvent(event))
    {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _win.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        _pause = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        _pause = false;
    }
}

void Game::debug_collision()
{
    sf::RectangleShape tmp;
    tmp.setOutlineColor(sf::Color::White);
    tmp.setOutlineThickness(1);
    tmp.setFillColor(sf::Color::Black);
    tmp.setSize(sf::Vector2f
        ((_scene[0]->getRekt().width), _scene[0]->getRekt().height));
    tmp.setPosition(sf::Vector2f
        ((_scene[0]->getRekt().left), _scene[0]->getRekt().top));
    _win.draw(tmp);
}

void Game::draw_and_display()
{
    // _bg.draw(_win);
    for (auto it = _scene.begin() ; it != _scene.end(); ++it)
    {
        if (DEBUG)
            debug_collision();
        (*it)->draw(_win);
    }

    if (DEBUG)
        for (auto it = _scene_debug.begin() ; it != _scene_debug.end(); ++it)
            _win.draw(*it);

    for (auto it = _ground.begin() ; it != _ground.end(); ++it)
        _win.draw((*it).line);

    if (_pause && !_winn && !_itsOver)
        _ui.drawInformation(_win, _mainView, 3);
    else if (_winn)
        _ui.drawInformation(_win, _mainView, 1);
    else if (_itsOver)
        _ui.drawInformation(_win, _mainView, 2);

    _win.setView(_mainView);
    _ui.draw(_win);
    _win.display();
}

void Game::moveView_and_ui()
{
    _mainView.setCenter(_scene[0]->getPos().x, WINY / 2);
    _ui.setPosition(_mainView.getCenter().x +
    (_mainView.getSize().x / 2) - 200, 20);
}

void Game::update()
{
    if (!_pause)
    {
    for (auto it = _scene.begin() ; it != _scene.end(); ++it)
    {
        (*it)->update();
        if (_scene[0]->checkC(**it) == 1 && (*it)->getId() == PLATFORM)
        {
            _winn = true;
            _pause = true;
        }
    }                
    for (auto it2 = _ground.begin() ; it2 != _ground.end(); ++it2)
        if (_scene[0]->checkC((*it2)._c) == 1) // && different de platform
        {
            _itsOver = true;
            _pause = true;
        }
    // debug();
    moveView_and_ui();
    _ui.getInformation(_scene[0]);    
    }
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