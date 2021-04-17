#include <vector>
#include "constants.cpp"
#include "Rect_Block/RectBlock.cpp"

using std::vector;

vector<RectBlock> generateBlocks(size_t amount)
{
    vector<RectBlock>blocks;

    float offset = 0.f;
    float rectLength = (RESOLUTION_X/(float)amount);


    for(int i = 0; i < amount; i++)
    {
        RectBlock block(rectLength,100.f, offset, RESOLUTION_Y-100);
        blocks.push_back(block);
        offset += rectLength;
    }

    return blocks;
}


int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X,RESOLUTION_Y), TITLE);

    vector<RectBlock>list_of_all_blocks = generateBlocks(5);

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