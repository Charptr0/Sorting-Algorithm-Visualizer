#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <iostream>

class Text
{
    private:
        sf::Font font; //the default font is arial
        sf::Text text;
        float position_x;
        float position_y;

    public:
        Text(const std::string &string, const float &posX, const float &posY, const float &font_size = 1);
        
        //empty constructor
        Text();

        void updateText(const std::string &new_string);

        //use this function for screen.draw()
        sf::Text getText();

};


