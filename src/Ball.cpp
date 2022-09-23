#include "Ball.hpp"

Ball::Ball(float radius)
:ballCircle(radius), ID()
{
    ballCircle.setOrigin(radius, radius);
    ballCircle.setFillColor(sf::Color(0, 0, 0, 0));
    ballCircle.setOutlineThickness(1);
    ballCircle.setOutlineColor(sf::Color(255, 255, 255));
}

void Ball::assignId(uint16_t p_ID)
{
    ID = p_ID;
}

bool Ball::checkBound(sf::Vector2f pos)
{
    if(ballCircle.getGlobalBounds().contains(pos) == true)
        return true;
    return false;
}

void Ball::drawTo(sf::RenderWindow& window)
{
    window.draw(ballCircle);
}

