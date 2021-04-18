#pragma once

#include <SFML/Graphics.hpp>

/*
RectBlock class:
*/

enum axis
{
    x, y
};

class RectBlock
{
    private:
        //position: x = [0], y = [1]
        float position[2];

        float length;
        float height;

        int value;

        sf::Color color = sf::Color::White;
        sf::Color borderColor = sf::Color::Green;
        sf::RectangleShape block;

        void setBlockPosition();
        void setBlockColor();
        void setSize();


    public:

        //main constructor
        RectBlock(const float &length, const float &height, const float &positionX, const float &positionY, const int &value);

        //set a new position for the rectangle
        void setPosition(const float &positionX, const float &positionY);

        //change the color of the rectangle
        void changeColor(const sf::Color &color);

        //change the color of the rectangle back to the default color: white
        void changeBackToDefaultColor();

        //get the rectangle's x value
        float getPositionX();

        //get the rectangle's y value
        float getPositionY();

        //get the height
        float getValue();

        //return the rectangle offered by SFML
        sf::RectangleShape display(); 

};