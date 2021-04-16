//#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.cpp"
#include "Rect_Block/RectBlock.cpp"

using std::vector;

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE);

    RectBlock r1(50.f,100.f,0,RESOLUTION_Y-100);
    RectBlock r2(50.f,200.f,50,RESOLUTION_Y-200);

    /*
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 100.f));
    sf::RectangleShape rectangle2(sf::Vector2f(50.f, 200.f));

    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(sf::Vector2f(0,RESOLUTION_Y-100));

    rectangle2.setFillColor(sf::Color::White);
    rectangle2.setPosition(sf::Vector2f(50,RESOLUTION_Y-200));
    */

    while(screen.isOpen())
    {
        sf::Event event;
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                screen.close();
        }

        screen.clear(sf::Color::Black);
        screen.draw(r1.display());
        screen.draw(r2.display());
        screen.display();

    }

}