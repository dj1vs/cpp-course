#include <iostream>
#include <cmath>

int main()
{
    long int number = 600851475143;
    int largest_prime_factor = 1;
    for (long i = 2; i <= sqrt(number); i += 1)
    {
        if (number % i != 0)
        {
            continue;
        }

        bool is_prime = true;
        for (long j = 2; j <= sqrt(i); j += 1)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (!is_prime)
        {
            continue;
        }

        largest_prime_factor = i;
    }

    std::cout << largest_prime_factor << std::endl;
}