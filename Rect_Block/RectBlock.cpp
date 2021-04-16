#include "RectBlock.h"

RectBlock::RectBlock(const float &length, const float &height, const float &positionX, const float &positionY, const float &size_multiplier)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->size_multiplier = size_multiplier;
    this->length = length;
    this->height = height;

    this->setBlockPosition();
    this->resizeBlock();
    this->setBlockColor();
}

void RectBlock::setBlockPosition() {block.setPosition(sf::Vector2f(this->position[axis::x], this->position[axis::y]));}

void RectBlock::resizeBlock() {block.setSize(sf::Vector2f(this->length, (this->height * this->size_multiplier)));}

void RectBlock::setBlockColor() {block.setFillColor(this->color);}

void RectBlock::setPosition(const float &positionX, const float &positionY)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->setBlockPosition();
}

float RectBlock::getPositionX() {return this->position[axis::x];}
float RectBlock::getPositionY() {return this->position[axis::y];}
float RectBlock::getSize() {return this->size_multiplier;}
sf::RectangleShape RectBlock::display() {return this->block;}


