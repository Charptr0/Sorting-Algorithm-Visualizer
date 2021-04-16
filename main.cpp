#include <SFML/Graphics.hpp>
#include "constants.cpp"

int main()
{
    sf::RenderWindow screen;
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 100.f));
    sf::RectangleShape rectangle2(sf::Vector2f(50.f, 200.f));

    //rectangle.setOutlineThickness(5);
    //rectangle.setOutlineColor(sf::Color::Magenta);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(sf::Vector2f(0,RESOLUTION_Y-100));

    rectangle2.setFillColor(sf::Color::Green);
    rectangle2.setPosition(sf::Vector2f(50,RESOLUTION_Y-2000));


    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), "Sorting Algorithm Visualizer");
    
    while(screen.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (screen.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                screen.close();
        }

        screen.clear(sf::Color::Black);
        screen.draw(rectangle);
        screen.draw(rectangle2);
        screen.display();

    }

}