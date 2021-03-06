#include "Algorithms/algo_list.cpp"
#include "Algorithms/bubblesort.cpp"
#include "Algorithms/selectionsort.cpp"
#include "Algorithms/insertionsort.cpp"
#include "Algorithms/mergesort.cpp"
#include "Algorithms/quicksort.cpp"
#include "Algorithms/heapsort.cpp"

const std::string TITLE = "Sorting Algorithm Visualizer";

//reset the comparsions counter and the clock
void reset()
{
    Number_of_comparsions = 0;
    GlobalClock.restart();
}

//display the upNext text and change the sorting algorithm
void upNext(sf::RenderWindow &screen, char &currentSort, const char nextSort)
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

        case INSERTION_SORT:
            next_algo_name += "Insertionsort";
            break;

        case MERGE_SORT:
            next_algo_name += "Mergesort";
            break;

        case QUICK_SORT:
            next_algo_name += "Quicksort";
            break;

        case HEAP_SORT:
            next_algo_name += "Heapsort";
            break;

        default:
            break;
    }

    Text upNextText(next_algo_name, 0, 100, TEXT_SIZE);

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

    char currentSort = BUBBLE_SORT; //set the first sorting algorithm to be bubble sort

    vector<int>nums; //array to hold the random numbers

    GlobalClock.restart(); //set the timer back to 0

    while(screen.isOpen())
    {
        grabEvents(screen); //grab events

        //base on what the currentSort is set to, it will display that algorithm
        switch(currentSort)
        {
            case BUBBLE_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Bubblesort");

                nums = numberGenerator(100); //create the array of unsorted numbers
                
                bubbleSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, SELECTION_SORT); //display the "up next" text
                reset();
                break;

            case SELECTION_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Selectionsort");

                nums = numberGenerator(100); //create the array of unsorted numbers
                
                selectionSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, INSERTION_SORT); //display the "up next" text
                reset();
                break;

            case INSERTION_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Insertionsort");

                nums = numberGenerator(100); 

                insertionSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, MERGE_SORT);
                reset();
                break;

            case MERGE_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Mergesort");

                nums = numberGenerator(250);
                
                mergeSort(nums, 0, nums.size()-1, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, QUICK_SORT); 
                reset();
                break;

            case QUICK_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Quicksort");

                nums = numberGenerator(250);
                
                quickSort(nums, 0, nums.size()-1, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, HEAP_SORT);
                reset();
                break;

            case HEAP_SORT:
                CurrentAlgorithmText.updateText("Current Algorithm: Heapsort");

                nums = numberGenerator(250);
                
                heapSort(nums, screen);
                colorBlocksGreen(nums, screen);
                
                upNext(screen, currentSort, BUBBLE_SORT); 
                reset();
                break;

            default:
                break;
        }
    }

}