#pragma once

#include <SFML/Graphics.hpp>

enum axis
{
    x, y
};

class RectBlock
{
    private:

        float position[2];
        float size_multiplier;
        float length;
        float height;
        int value;

        sf::Color color = sf::Color::White;
        sf::Color borderColor = sf::Color::Green;
        sf::RectangleShape block;

        void setBlockPosition();
        void setBlockColor();
        void resizeBlock();


    public:

        RectBlock(const float &length, const float &height, const float &positionX, const float &positionY, const float &size_multiplier = 1);
        void setPosition(const float &positionX, const float &positionY);
        void resize(const float &length, const float &height);
        float getPositionX();
        float getPositionY();
        float getSize();
        sf::RectangleShape display();

};