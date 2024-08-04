#include <iostream>

void draw_tree(int tree_len)
{
    if (tree_len < 0 || tree_len > 15)
    {
        std::cout << "Неправильная длина дерева!\n";
        return;
    }

    int tree_width = tree_len * 2 - 1;
    int dots_amount = 1;
    for (int i = 0; i < tree_len; ++i)
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
    int tree_len;
    std::cin >> tree_len;
    draw_tree(tree_len);
}