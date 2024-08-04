#include <iostream>

std::string dec_to_hex(int a)
{
    std::string hex;
    while (a > 0)
    {
        int remainder = a % 16;
        if (remainder < 10)
        {
            hex += '0' + remainder;
        }
        else
        {
            hex += (remainder - 10) + 'A';
        }
        a /= 16;
    }

    std::string reversed_hex;
    for (int i = hex.size() - 1; i >= 0; i -= 1)
    {
        reversed_hex += hex[i];
    }

    return reversed_hex;
}

int main()
{
    int a;
    std::cin >> a;
    std::cout << dec_to_hex(a) << std::endl;
}