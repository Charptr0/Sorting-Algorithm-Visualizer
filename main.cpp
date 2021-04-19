#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime> //random number generator
#include "constants.cpp"


using std::vector;

vector<int> numberGenerator(size_t amount, size_t upperBound = 100)
{
    srand(time(NULL)); //start the clock

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
    sf::Event event;
    while (screen.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            screen.close();
    }
}

void drawToScreen(vector<int>&nums, sf::RenderWindow &screen)
{
    screen.clear(sf::Color::Black);

    float offset_x = 0.f;
    float rectLength = (RESOLUTION_X/(float)nums.size());

    for(int i = 0; i < nums.size(); i++)
    {
        grabEvents(screen);
        float rectHeight = nums[i] * SIZE_AMPLIFIER;
        sf::RectangleShape block;
        block.setFillColor(sf::Color::White);
        block.setPosition(sf::Vector2f(offset_x, RESOLUTION_Y-rectHeight));
        block.setSize(sf::Vector2f(rectLength, rectHeight));
        screen.draw(block);
        offset_x += rectLength;
    }

    screen.display();
}

void bubbleSort(vector<int>&nums, sf::RenderWindow &screen)
{
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size()-1; j++)
        {
            grabEvents(screen);

            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }

            drawToScreen(nums, screen); 
        }
    }
}


int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE);

    vector<int>nums = numberGenerator(1000);

    while(screen.isOpen())
    {
        grabEvents(screen);
        bubbleSort(nums, screen);
    }

}