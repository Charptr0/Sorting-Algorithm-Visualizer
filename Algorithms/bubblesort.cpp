#include "../draw_blocks.cpp"

void bubbleSort(vector<int>&nums, sf::RenderWindow &screen)
{
    //normal bubblesort algorithm
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size()-1; j++)
        {
            grabEvents(screen);
            
            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }

            drawToScreen(nums, screen); //draw the state of the rectangles after 1 comparison 
        }
    }
}

void bubbleSortFast(vector<int>&nums, sf::RenderWindow &screen)
{
    //normal bubblesort algorithm
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size()-1; j++)
        {
            grabEvents(screen);
            
            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }

        drawToScreen(nums, screen); //draw the state of the rectangle after nums.size()-1 comparsions
    }    
}