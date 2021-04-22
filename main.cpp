#include "Algorithms/bubblesort.cpp"

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE); //create the screen and add the title

    //temp var fixing it later
    bool sorted = false;
    bool temp = false;

    vector<int>nums = numberGenerator(90); //create the number of rectangles

    GlobalClock.restart(); //set the timer back to 0

    while(screen.isOpen())
    {
        grabEvents(screen);

        if(!sorted) {bubbleSort(nums, screen); sorted = true;}
        if(!temp) {colorBlocksGreen(nums, screen); temp = true;}
    }

}