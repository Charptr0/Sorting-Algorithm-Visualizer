//==================================================================================
//Bubblesort forever visualizer
//The algorithms will use bubblesort to sort blocks until the size reaches 250
//After reaching 250, the size will go back to 50
//TLDR: this program will run forever **great for a screensaver**
//===================================================================================

#include "Algorithms/bubblesort.cpp"

const std::string TITLE = "Sorting Algorithm Visualizer";

void intermission(sf::RenderWindow &screen, int &block_amount)
{
    if(block_amount > 250) {block_amount = 50;}
    else {block_amount += 10;}

    std::string next_block_amount = "Up Next: " + std::to_string(block_amount) + " blocks";

    Text upNextText(next_block_amount, RESOLUTION_X-(RESOLUTION_X*0.7), RESOLUTION_Y-(RESOLUTION_Y*0.8));

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
}

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE); //create the screen and add the title

    int block_amount = 250;

    vector<int>nums; //array to hold the random numbers

    GlobalClock.restart(); //set the timer back to 0

    while(screen.isOpen())
    {
        grabEvents(screen);

        nums = numberGenerator(block_amount); //generate the a bunch of unsorted numbers

        bubbleSort(nums, screen); 
        colorBlocksGreen(nums, screen);

        intermission(screen, block_amount); //display the "up next" text
        Number_of_comparsions = 0; //reset the comparsion # back to 0
    }
}