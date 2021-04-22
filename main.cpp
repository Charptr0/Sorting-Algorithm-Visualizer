#include "Algorithms/algo_list.cpp"
#include "Algorithms/bubblesort.cpp"

const std::string TITLE = "Sorting Algorithm Visualizer";


int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE); //create the screen and add the title

    char currentSort = BUBBLE_SORT; //set the current sorting algo to be bubble sort

    vector<int>nums; //array to hold the random numbers

    GlobalClock.restart(); //set the timer back to 0

    while(screen.isOpen())
    {
        grabEvents(screen);

        switch(currentSort)
        {
            case BUBBLE_SORT:
                nums = numberGenerator(100); //create the number of rectangles
                bubbleSort(nums, screen);
                colorBlocksGreen(nums, screen);

                currentSort = NONE;
                break;

            default:
                break;
        }
    }

}