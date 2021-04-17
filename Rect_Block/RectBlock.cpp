#include "RectBlock.h"

RectBlock::RectBlock(const float &length, const float &height, const float &positionX, const float &positionY, const int &value)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->length = length;
    this->height = height;
    this->value = value;

    this->setBlockPosition();
    this->resizeBlock();
    this->setBlockColor();
}

void RectBlock::setBlockPosition() {block.setPosition(sf::Vector2f(this->position[axis::x], this->position[axis::y]));}

void RectBlock::setBlockColor() 
{
    block.setFillColor(this->color);
    block.setOutlineColor(this->borderColor);
    block.setOutlineThickness(1.0f);
}

void RectBlock::setPosition(const float &positionX, const float &positionY)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->setBlockPosition();
}

void RectBlock::changeColor(const sf::Color &color) {this->block.setFillColor(color);}

void RectBlock::changeBackToDefaultColor() {this->block.setFillColor(sf::Color::White);}

float RectBlock::getPositionX() {return this->position[axis::x];}
float RectBlock::getPositionY() {return this->position[axis::y];}

sf::RectangleShape RectBlock::display() {return this->block;}


