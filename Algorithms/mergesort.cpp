#include "../draw_blocks.cpp"

void merge(vector<int>&nums, int left, int mid, int right, sf::RenderWindow &screen)
{
	vector<int>temp;

	int i = left; //left ptr for left array
	int j = mid+1; //right ptr for right array

	while(i < (mid+1) && j < right+1)
	{
        ComparsionText.updateText(std::to_string(++Number_of_comparsions) + " Comparsions");

		if(nums[i] <= nums[j])
		{
			temp.push_back(nums[i]);
			i++;
		}

		else
		{
			temp.push_back(nums[j]);
			j++;
		}
        
        drawToScreen(nums,screen);
	}

	while(i < mid+1)
	{
		temp.push_back(nums[i]);
		i++;
	}

	while(j < right+1)
	{
		temp.push_back(nums[j]);
		j++;
	}

	for(int i = left; i < right+1; i++)
	{
		nums[i] = temp[i - left];
	}
}

void mergeSort(vector<int>&nums, int left, int right, sf::RenderWindow &screen)
{
    if(left < right)
    {
        int mid = (left+right) / 2;
        mergeSort(nums, left, mid, screen);
        mergeSort(nums, mid+1, right, screen);
        merge(nums, left, mid, right, screen);
    }
}