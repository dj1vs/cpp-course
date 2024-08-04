#include <iostream>

int main()
{
    int max_palindrome = -1;
    for (int i = 100; i < 1000; ++i)
    {
        for (int j = i + 1; j < 1000; ++j)
        {
            int number = i * j;

            std::string number_str;
            while (number > 0)
            {
                number_str += ('0' + number % 10);
                number /= 10;
            }

            bool is_palindrome = true;
            for (int k = 0; k < number_str.size()/2; ++k)
            {
                if (number_str[k] != number_str[number_str.size() - 1 - k])
                {
                    is_palindrome = false;
                    break;
                }
            }

            if (!is_palindrome)
            {
                continue;
            }

            if (i * j > max_palindrome)
            {
                max_palindrome = i * j;
            }
        }
    }

    std::cout << max_palindrome << std::endl;
}