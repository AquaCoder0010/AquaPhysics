#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
    public:
        sf::CircleShape ballCircle;
        sf::Vertex line[2];
        uint16_t ID;
    public:
        Ball(float radius);
        void assignId(uint16_t p_ID);  
        void drawTo(sf::RenderWindow& window);
        bool checkBound(sf::Vector2f pos);
    public:
        sf::CircleShape* getballPointer()
        {
            return &ballCircle;
        }
        uint16_t getID()
        {
            return ID;
        }

};