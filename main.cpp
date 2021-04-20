#include <SFML/Graphics.hpp>
#include <vector> //dynamic array to store numbers
#include <ctime> //random number generator
#include "constants.cpp"
#include "Text_Manager/text.cpp"

using std::vector;

//global variables
int Number_of_comparsions = 0;
Text ComparsionText("Comparsions Made: " + std::to_string(Number_of_comparsions), 0, 0, 0.8f);
//global variables

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

//this is here to prevent the window from freezing, idk any good way to do this
//this does the job, dont touch plz
//scatter this function into other sorting functions to prevent it from freezing
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
        block.setPosition(sf::Vector2f(offset_x, RESOLUTION_Y-rectHeight)); //set the position
        block.setSize(sf::Vector2f(rectLength, rectHeight)); 

        screen.draw(block); //draw the block to the screen

        offset_x += rectLength; //increase the x value so it is ready for the next rectangle
    }

    screen.draw(ComparsionText.getText());
    screen.display();
}

void bubbleSort(vector<int>&nums, sf::RenderWindow &screen)
{
    //normal bubblesort algorithm
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size()-1; j++)
        {
            grabEvents(screen);
            
            ComparsionText.updateText("Comarsion Made: " + std::to_string(++Number_of_comparsions));

            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }

            drawToScreen(nums, screen); //draw the state of the rectangles after 1 comparison 
        }

        //drawToScreen(nums, screen); 
    }
}

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
        block.setPosition(sf::Vector2f(offset_x, RESOLUTION_Y-rectHeight));
        block.setSize(sf::Vector2f(rectLength, rectHeight));

        screen.draw(block);

        offset_x += rectLength;
        //same code from drawToScreen()
    }

    screen.draw(ComparsionText.getText());
    screen.display();

    colorBlocksGreen(nums, screen, ++index);  //recursion, increment the index by 1
}

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE); //create the screen and add the title

    bool sorted = false;
    bool temp = false;

    vector<int>nums = numberGenerator(100); //create the number of rectangles

    while(screen.isOpen())
    {
        grabEvents(screen);

        if(!sorted) {bubbleSort(nums, screen); sorted = true;}
        if(!temp) {colorBlocksGreen(nums, screen); temp = true;}

    }

}