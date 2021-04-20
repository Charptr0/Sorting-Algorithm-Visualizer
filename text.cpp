#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>

sf::Font main_font;

void textInit()
{
    if(!main_font.loadFromFile("Fonts/arial.ttf")) {std::cout << "An error has occurred while loading font\n";}
}






