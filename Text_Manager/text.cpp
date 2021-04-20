#include "text.h"

const std::string FONT_FILE_PATH = "Text_Manager/Fonts/arial.ttf";

Text::Text(const std::string &string, const float &posX, const float &posY, const float &font_size)
{
    if(!this->font.loadFromFile(FONT_FILE_PATH)) {std::cout << "An error has occurred while loading the font\n";}

    this->position_x = posX;
    this->position_y = posY;

    this->text.setFillColor(sf::Color::White);
    this->text.setFont(this->font);
    this->text.setString(string);
    this->text.setPosition(sf::Vector2f(this->position_x, this->position_y));
    this->text.setScale(sf::Vector2f(font_size, font_size));
}

Text::Text()
{
    if(!this->font.loadFromFile(FONT_FILE_PATH)) {std::cout << "An error has occurred while loading the font\n";}
    this->text.setFillColor(sf::Color::White);
    this->text.setFont(this->font);
    this->text.setString("");
    this->text.setScale(sf::Vector2f(1.0f, 1.0f));
}

void Text::updateText(const std::string &new_string) {this->text.setString(new_string);}

sf::Text Text::getText() {return this->text;}