#include "../draw_blocks.cpp"

void selectionSort(vector<int>&nums, sf::RenderWindow &screen)
{
    //normal selectionsort algorithm
    for(int i = 0; i < nums.size(); i++)
    {
        int smallest = nums[i];
        int smallest_index = i;
        
        for(int j = i; j < nums.size(); j++)
        {
            if(nums[j] < smallest) {smallest = nums[j]; smallest_index = j;}

            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");
            drawToScreen(nums, screen); //draw the state of the rectangles after 1 comparison 
        }


        int temp = nums[i];
        nums[i] = nums[smallest_index];
        nums[smallest_index] = temp;

        //drawToScreen(nums, screen);
    }
}

void selectionSortFast(vector<int>&nums, sf::RenderWindow &screen)
{
    //normal selectionsort algorithm
    for(int i = 0; i < nums.size(); i++)
    {
        int smallest = nums[i];
        int smallest_index = i;
        
        for(int j = i; j < nums.size(); j++)
        {
            if(nums[j] < smallest) {smallest = nums[j]; smallest_index = j;}

            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");
        }


        int temp = nums[i];
        nums[i] = nums[smallest_index];
        nums[smallest_index] = temp;

        drawToScreen(nums, screen); //draw the state of the rectangle after nums.size()-1 comparsions
    }
}