#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Color background {0, 0, 0};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) {
                background = sf::Color {rand() % 255, rand() % 255, rand() % 255};
            }
        }

        window.clear(background);
        window.draw(shape);
        window.display();
    }

    return 0;
}