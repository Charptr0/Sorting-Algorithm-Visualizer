#include <RectBlock.h>
//#include <SFML/System/Vector2.hpp>

RectBlock::RectBlock(const float &positionX, const float &positionY, const float &size)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->size = size;
    this->setBlockPosition();
    this->setBlockColor();
}

void RectBlock::setBlockPosition()
{
    block.setSize(sf::Vector2f(10.f,10.f));
    block.setPosition(sf::Vector2f(this->position[axis::x], this->position[axis::y]));
}

void RectBlock::setBlockColor() {block.setFillColor(this->color);}

void RectBlock::setPosition(const float &positionX, const float &positionY)
{
    this->position[axis::x] = positionX;
    this->position[axis::y] = positionY;
    this->setBlockPosition();
}

float RectBlock::getPositionX() {return this->position[axis::x];}
float RectBlock::getPositionY() {return this->position[axis::y];}
float RectBlock::getSize() {return this->size;}


