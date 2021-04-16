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
        sf::Color color = sf::Color::White;
        float size;
        sf::RectangleShape block;

        void setBlockPosition();
        void setBlockColor();


    public:
        RectBlock(const float &positionX, const float &positionY, const float &size);
        void setPosition(const float &positionX, const float &positionY);
        float getPositionX();
        float getPositionY();
        float getSize();

};