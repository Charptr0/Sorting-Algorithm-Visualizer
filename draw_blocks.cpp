#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include "constants.cpp"
#include "Text_Manager/text.cpp"

using std::vector;

sf::Clock GlobalClock;
int Number_of_comparsions = 0;
Text ComparsionText(std::to_string(Number_of_comparsions) + "Comparsions", 0, 0, TEXT_SIZE);
Text AuthorText("Made by Charptr0", 0, 25, TEXT_SIZE);
Text ElaspedTimeText("Elasped Time: 0s", 0, 50, TEXT_SIZE);
Text CurrentAlgorithmText("", 0, 75, TEXT_SIZE);

void grabEvents(sf::RenderWindow &screen) 
{
    //SFML event boiler code
    sf::Event event;
    while (screen.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            screen.close();
    }
    //SFML event boiler code
}

//generate a random number
vector<int> numberGenerator(size_t amount, size_t upperBound = 100)
{
    srand(time(NULL)); 

    vector<int>randomNums;

    for(size_t i = 0; i < amount; i++)
    {
        int rand_num = rand() % (upperBound + 1);
        rand_num++;

        randomNums.push_back(rand_num);
    }

    return randomNums;
}

//draw the rectangle blocks to the screen
void drawToScreen(vector<int>&nums, sf::RenderWindow &screen)
{
    screen.clear(sf::Color::Black); //clear the screen and set the background to black

    float offset_x = 0.f;
    float rectLength = (RESOLUTION_X/(float)nums.size()); //calculate the length of the rectangle

    for(int i = 0; i < nums.size(); i++)
    {
        grabEvents(screen);

        float rectHeight = nums[i] * SIZE_AMPLIFIER; //calculate the height of the rectangle
        sf::RectangleShape block;

        block.setFillColor(sf::Color::White); //set the rectangle color to white
        block.setOutlineColor(sf::Color::Black);
        block.setOutlineThickness(1.f);
        block.setPosition(sf::Vector2f(offset_x, RESOLUTION_Y-rectHeight)); //set the position
        block.setSize(sf::Vector2f(rectLength, rectHeight)); 

        screen.draw(block); //draw the block to the screen

        offset_x += rectLength; //increase the x value so it is ready for the next rectangle
    }

    //display text
    //==========================================================================================
    screen.draw(ComparsionText.getText());
    screen.draw(AuthorText.getText());

    sf::Time elaspedTime = GlobalClock.getElapsedTime();
    ElaspedTimeText.updateText("Elasped Time: " + std::to_string(elaspedTime.asSeconds()) + "s");
    screen.draw(ElaspedTimeText.getText());

    screen.draw(CurrentAlgorithmText.getText());
    screen.display();
    //==========================================================================================
}

//color the rectangle green when the algo is done
void colorBlocksGreen(const vector<int>&nums, sf::RenderWindow &screen, int index = 0)
{
    if(index == nums.size()) {return;} //base case: once it has cycle thru the whole array, terminate the function

    screen.clear();

    //same code from drawToScreen()
    float offset_x = 0.f;
    float rectLength = (RESOLUTION_X/(float)nums.size());
    //same code from drawToScreen()

    for(int i = 0; i < nums.size(); i++)
    {
        grabEvents(screen);

        //same code from drawToScreen()
        float rectHeight = nums[i] * SIZE_AMPLIFIER;
        sf::RectangleShape block;
        //same code from drawToScreen()

        //color each block green in ascending order
        if(i <= index) {block.setFillColor(sf::Color::Green);} //color the blocks green that is before the index var
        else {block.setFillColor(sf::Color::White);} //any block that is after the index var, color it white

        //same code from drawToScreen()
        block.setOutlineColor(sf::Color::Black);
        block.setOutlineThickness(1.f);
        block.setPosition(sf::Vector2f(offset_x, RESOLUTION_Y-rectHeight));
        block.setSize(sf::Vector2f(rectLength, rectHeight));

        screen.draw(block);

        offset_x += rectLength;
        //same code from drawToScreen()
    }


    screen.draw(ComparsionText.getText());
    screen.draw(AuthorText.getText());

    sf::Time elaspedTime = GlobalClock.getElapsedTime();
    ElaspedTimeText.updateText("Elasped Time: " + std::to_string(elaspedTime.asSeconds()) + "s");
    screen.draw(ElaspedTimeText.getText());

    screen.draw(CurrentAlgorithmText.getText());
    screen.display();

    colorBlocksGreen(nums, screen, ++index);  //recursion, increment the index by 1
}



