#include <iostream>

int main()
{
    long long number = 20;
    while (true)
    {
        bool is_correct = true;
        for (int i = 1; i <= 20; i += 1)
        {
            if (number % i != 0)
            {
                is_correct = false;
                break;
            }
        }

        if (!is_correct)
        {
            number += 20;
            continue;
        }

        std::cout << number << std::endl;
        break;
    }
}