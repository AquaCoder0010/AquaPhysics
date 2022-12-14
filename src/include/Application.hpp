#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "Ball.hpp"

class Application
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock clock;
        std::vector<Ball> vecBalls;
        int timer = 0;
    private:
        sf::Font font;
        sf::Text fpsText;
        sf::Time currTimer;
        int fps = 0;
        int frame = 0;
    public:
        Application(int win_x, int win_y);
        ~Application();
        void run();
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
};

