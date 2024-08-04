#include <iostream>

int main()
{
    int odd_number = 1;
    int i = 0;
    while (i < 10)
    {
        std::cout << odd_number << ' ';
        odd_number += 2;
        i = i + 1;
    }
}