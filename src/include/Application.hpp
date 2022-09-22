#pragma once
#include <SFML/Graphics.hpp>

class Application
{
    private:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock clock;
        sf::Vector2i windowSize;
    public:
        Application(int win_x, int win_y);
        ~Application();
        void run();
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
};

