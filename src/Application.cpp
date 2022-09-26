#include "Application.hpp"

static bool mouseLeft = false;

Application::Application(int win_x, int win_y)
:window(sf::VideoMode(win_x, win_y), "Physics Engine"), clock(), timer(0), currTimer(), fpsText(), font()
{    
    font.loadFromFile("rsrc/Fonts/font.ttf");
    fpsText.setFont(font);
    fpsText.setCharacterSize(15);
    fpsText.setPosition(sf::Vector2f(fpsText.getCharacterSize(), fpsText.getCharacterSize()));

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
        sf::Time deltaTime = clock.restart();
        currTimer += deltaTime;
        processEvents();
        update(deltaTime);
        render();

        if(currTimer.asSeconds() > 1.f)
        {
            fps = frame; frame = 0; currTimer = sf::Time::Zero; 
        }
        frame++;
        fpsText.setString("FPS : - " + std::to_string(fps));
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
        vecBalls.emplace_back(Ball(rand() % 40));
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
        for(auto& target : vecBalls)
        {
            if(ball.ID != target.ID)
            {
                sf::Vector2f ballPos = ball.ballCircle.getPosition();
                sf::Vector2f targetPos = target.ballCircle.getPosition();
                
                if((ballPos.x - targetPos.x)*(ballPos.x - targetPos.x) + (ballPos.y - targetPos.y)*(ballPos.y - targetPos.y) < (ball.radius()+target.radius())*(ball.radius()+target.radius()))
                {
                    float distance = sqrt((ballPos.x - targetPos.x)*(ballPos.x - targetPos.x) + (ballPos.y - targetPos.y)*(ballPos.y - targetPos.y));
                    float overlap = (distance - ball.radius() - target.radius())/2.f;

                    ballPos.x -= overlap * (ballPos.x - targetPos.x) / distance;
                    ballPos.y -= overlap * (ballPos.y - targetPos.y) / distance;

                    targetPos.x += overlap * (ballPos.x - targetPos.x) / distance;
                    targetPos.y += overlap * (ballPos.y - targetPos.y) / distance;

                    ball.ballCircle.setPosition(ballPos);
                    target.ballCircle.setPosition(targetPos);

                }
            }
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
    window.draw(fpsText);
    window.display();
}

