#include <iostream>

int main()
{
    int sum = 0;
    int first_fib = 1;
    int second_fib = 1;
    while (first_fib + second_fib < 4000000)
    {
        int cur_fib = first_fib + second_fib;
        if (cur_fib % 2 == 0)
        {
            sum += cur_fib;
        }
        first_fib = second_fib;
        second_fib = cur_fib;
    }

    std::cout << sum << std::endl;
}