#include <iostream>

int main()
{
    int multiples_sum = 0;
    for (int i = 3; i < 1000; i += 1)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            multiples_sum += i;
        }
    }

    std::cout << multiples_sum << std::endl;
}