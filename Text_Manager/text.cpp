#include "text.h"

const std::string FONT_FILE_PATH = "Text_Manager/Fonts/arial.ttf";

Text::Text(const std::string &string, const float &posX, const float &posY, const float &font_size)
{
    if(!this->font.loadFromFile(FONT_FILE_PATH)) {std::cout << "An error has occurred while loading the font\n";} //load arial font

    //set the position of the text
    this->position_x = posX; 
    this->position_y = posY;
    //set the position of the text


    this->text.setFillColor(sf::Color::White); //set the color of the text to white
    this->text.setFont(this->font); //set the font
    this->text.setString(string); //set the text
    this->text.setPosition(sf::Vector2f(this->position_x, this->position_y)); //set the position
    this->text.setScale(sf::Vector2f(font_size, font_size)); //set the size
}

Text::Text()
{
    if(!this->font.loadFromFile(FONT_FILE_PATH)) {std::cout << "An error has occurred while loading the font\n";} //load arial font
    
    this->text.setFillColor(sf::Color::White);
    this->text.setFont(this->font);
    this->text.setString("");
    this->text.setScale(sf::Vector2f(1.0f, 1.0f));
}

void Text::updateText(const std::string &new_string) {this->text.setString(new_string);}

sf::Text Text::getText() {return this->text;}