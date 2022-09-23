#include "Application.hpp"

static bool mouseLeft = false;

Application::Application(int win_x, int win_y)
:window(sf::VideoMode(win_x, win_y), "Physics Engine"), clock(), timer(0)
{    
    for(int i = 0; i < 10; i++)
    {
        vecBalls.push_back(Ball((rand() % 20) + 10));
    }
    for(auto& ball : vecBalls)
    {
        ball.assignId(rand()); 
        ball.ballCircle.setPosition(sf::Vector2f(rand() % window.getSize().x - ball.ballCircle.getRadius(), 
                                                 rand() % window.getSize().y - ball.ballCircle.getRadius()));
    }
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
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
                mouseLeft = false;
        }

        if(event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
                mouseLeft = true;
        }
    }

    std::cout << mouseLeft << '\n';
}

void Application::update(sf::Time deltaTime)
{   
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true && timer == 0)
    {
        vecBalls.emplace_back(Ball(rand() % 10));
        vecBalls.back().assignId(rand());
        vecBalls.back().ballCircle.setPosition(static_cast<sf::Vector2f>(mousePos));
        timer = 100;
    }

    if(timer > 0)
        timer--;


    for(auto& ball : vecBalls)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == true && ball.checkBound(static_cast<sf::Vector2f>(mousePos)) == true)
        {
            ball.ballCircle.setPosition(static_cast<sf::Vector2f>(mousePos));
        }
    }
}

void Application::render()
{
    window.clear();
    for(auto& ball : vecBalls)
    {
        ball.drawTo(window);
    }
    window.display();
}

