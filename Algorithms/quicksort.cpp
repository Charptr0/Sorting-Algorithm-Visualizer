#include "../draw_blocks.cpp"

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int partition(vector<int>&nums, int low, int high, sf::RenderWindow &screen)
{
    int i = low; //low ptr
    int j = low; //high ptr

    while(i < high && j < high)
    {
        ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

        if(nums[j] >= nums[high])
        {
            j++;
        }

        else
        {
            swap(nums[j], nums[i]);
            i++;
            j++;
        }

        drawToScreen(nums, screen);
    }

    swap(nums[i], nums[high]);

    drawToScreen(nums, screen);

    return i;
}

void quickSort(vector<int>&nums, int low, int high, sf::RenderWindow &screen)
{
    if(low < high)
    {
        int pivot = partition(nums, low, high, screen);
        quickSort(nums, low, pivot-1, screen);
        quickSort(nums, pivot+1, high, screen); 
    }
}