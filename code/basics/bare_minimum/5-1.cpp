#include <iostream>

int main()
{
    int odd_number = 1;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << odd_number << ' ';
        odd_number += 2;
    }
}