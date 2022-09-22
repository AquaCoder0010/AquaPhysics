#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML Application");
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    sf::Text text;
    if(font.loadFromFile("rsrc/Fonts/font.ttf"))
    {
        text.setFont(font);
    }
    text.setCharacterSize(15);
    text.setPosition(sf::Vector2f(text.getCharacterSize() + 10.f, text.getCharacterSize()));

    sf::Event event;
	sf::Time deltaTime;
    sf::Clock deltaTimeClock;
    sf::Clock clock;
    int Frame;
    int fps;
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime = deltaTimeClock.restart();
        //update loop

        //update Loop
        if(clock.getElapsedTime().asSeconds() >= 1.f)
		{
			fps = Frame; Frame = 0; clock.restart();
		}
		++Frame;
        text.setString("FPS :- " + std::to_string(fps));


        //render loop
        window.clear();
        window.draw(text);
        window.display();
    }
}