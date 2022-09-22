#include "Application.hpp"

Application::Application(int win_x, int win_y)
:window(sf::VideoMode(win_x, win_y), "Physics Engine"), windowSize(win_x, win_y), clock()
{

}

void Application::run()
{
    while(window.isOpen())
    {
        processEvents();
        update(clock.restart());
        render();
    }
}

void Application::processEvents()
{
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
    }
}

void Application::update(sf::Time deltaTime)
{

}

void Application::render()
{
    window.clear();
    window.display();
}