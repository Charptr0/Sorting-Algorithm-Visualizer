#include <vector>
#include <iostream>
#include <ctime> //random number generator
#include "constants.cpp"
#include "Rect_Block/RectBlock.cpp"

using std::vector;

vector<int> numberGenerator(size_t amount, size_t upperBound = 100)
{
    srand(time(NULL)); //start the clock

    vector<int>randomNums;

    for(size_t i = 0; i < amount; i++)
    {
        int rand_num = rand() % (upperBound + 1);
        rand_num++;

        randomNums.push_back(rand_num);
    }

    return randomNums;
}

vector<RectBlock> generateBlocks(size_t amount)
{
    vector<RectBlock>blocks;
    vector<int>randomNums = numberGenerator(amount, 300);

    float offset_x = 0.f;
    float rectLength = (RESOLUTION_X/(float)amount);


    for(int i = 0; i < amount; i++)
    {
        int block_value = (float)randomNums[i];
        float rectHeight = block_value * SIZE_AMPLIFIER;

        RectBlock block(rectLength, rectHeight, offset_x, RESOLUTION_Y-rectHeight, block_value);
        blocks.push_back(block);
        offset_x += rectLength;
    }

    return blocks;
}


int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE);

    vector<RectBlock>list_of_all_blocks = generateBlocks(100);

    while(screen.isOpen())
    {
        sf::Event event;
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                screen.close();
        }

        screen.clear(sf::Color::Black);

        for(int i = 0; i < list_of_all_blocks.size(); i++)
        {
            screen.draw(list_of_all_blocks[i].display());
        }

        screen.display();

    }

}