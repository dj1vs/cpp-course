#include <iostream>

void draw_tree()
{
    int tree_width = 5;
    int dots_amount = 1;
    for (int i = 0; i < 3; ++i)
    {
        int spaces_amount = tree_width - dots_amount;
        for (int j = 0; j < spaces_amount/2; ++j)
        {
            std::cout << ' ';
        }
        for (int j = 0; j < dots_amount; ++j)
        {
            std::cout << '*';
        }
        for (int j = 0; j < spaces_amount/2; ++j)
        {
            std::cout << ' ';
        }
        std::cout << '\n';
        dots_amount += 2;
    }
}

int main()
{
    draw_tree();
}