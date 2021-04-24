#include "../draw_blocks.cpp"

void insertionSort(vector<int>&nums, sf::RenderWindow &screen)
{
    for(int i = 1; i < nums.size(); i++)
    {
        int current_index = i;

        while(current_index >= 0)
        {
            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

            if(nums[current_index] < nums[current_index-1])
            {
                int temp = nums[current_index];
                nums[current_index] = nums[current_index-1];
                nums[current_index-1] = temp;
            }

            else {break;}

            drawToScreen(nums, screen);

            current_index--;
        }
    }
}

void insertionSortFast(vector<int>&nums, sf::RenderWindow &screen)
{
    for(int i = 1; i < nums.size(); i++)
    {
        int current_index = i;

        while(current_index >= 0)
        {
            ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

            if(nums[current_index] < nums[current_index-1])
            {
                int temp = nums[current_index];
                nums[current_index] = nums[current_index-1];
                nums[current_index-1] = temp;
            }

            else {break;}

            current_index--;
        }


        drawToScreen(nums, screen);
    }
}