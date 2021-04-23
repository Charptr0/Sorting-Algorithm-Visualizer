#include "Algorithms/algo_list.cpp"
#include "Algorithms/bubblesort.cpp"
#include "Algorithms/selectionsort.cpp"

const std::string TITLE = "Sorting Algorithm Visualizer";

void intermission(sf::RenderWindow &screen, char &currentSort, const char nextSort)
{
    std::string next_algo_name = "Up Next: ";

    //depending on the next sorting algo, update the text
    switch(nextSort)
    {
        case BUBBLE_SORT:
            next_algo_name += "Bubblesort";
            break;
        
        case SELECTION_SORT:
            next_algo_name += "Selectionsort";
            break;

        default:
            break;
    }

    Text upNextText(next_algo_name, RESOLUTION_X-(RESOLUTION_X*0.6), RESOLUTION_Y-(RESOLUTION_Y*0.8));

    GlobalClock.restart();
    sf::Time elaspedTime = GlobalClock.getElapsedTime();

    //notify the user of the next sort
    screen.draw(upNextText.getText());
    screen.display();

    while(elaspedTime.asSeconds() < 5.0f) //wait 5 seconds before the next sort
    {
        grabEvents(screen);
        elaspedTime = GlobalClock.getElapsedTime();
    }

    currentSort = nextSort; //update the currentSort to the next sort
}

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
                GlobalClock.restart(); //reset the elasped time
                CurrentAlgorithmText.updateText("Current Algorithm: Bubblesort");

                nums = numberGenerator(100); //create the array of unsorted numbers
                
                bubbleSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                intermission(screen, currentSort, SELECTION_SORT); //display the "up next" text
                Number_of_comparsions = 0; //reset the comparsions
                break;

            case SELECTION_SORT:
                GlobalClock.restart();
                CurrentAlgorithmText.updateText("Current Algorithm: Selectionsort");

                nums = numberGenerator(100); //create the array of unsorted numbers
                
                selectionSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                intermission(screen, currentSort, BUBBLE_SORT); //display the "up next" text
                Number_of_comparsions = 0; //reset the comparsions

            default:
                break;
        }
    }

}