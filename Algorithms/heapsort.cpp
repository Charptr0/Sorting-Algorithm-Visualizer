#include "../draw_blocks.cpp"

void heap_sort_swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>&nums, int size, int parent_index, sf::RenderWindow &screen)
{
    int largest = parent_index;
    int left_child_index = 2*parent_index+1;
    int right_child_index = 2*parent_index+2;

    if(left_child_index < size && nums[left_child_index] > nums[largest]) {largest = left_child_index;}
    if(right_child_index < size && nums[right_child_index] > nums[largest]) {largest = right_child_index;}

    if(largest != parent_index)
    {
        heap_sort_swap(nums[parent_index], nums[largest]);
        heapify(nums, size, largest, screen);
    }

    ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");
    drawToScreen(nums, screen);
}

void heapSort(vector<int>&nums, sf::RenderWindow &screen)
{
    int size = nums.size();

    //build max heap
    for(int i = (size/2)-1; i >= 0; i--)
    {
        heapify(nums, size, i, screen);
    }

    //remove and sort
    for(int i = size-1; i > 0; i--)
    {
        heap_sort_swap(nums[0], nums[i]); //delete the root
        heapify(nums, i, 0, screen);
    }
}