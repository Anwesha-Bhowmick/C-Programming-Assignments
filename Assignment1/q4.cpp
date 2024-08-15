#include <iostream>

int main()
{
    long int x, binary;
    int i;
    std::cout << "\nenter an integer: ";
    std::cin >> x;
    for (i = 31; i >= 0; i--)
    {
        binary = x >> i;
        if (binary & 1)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << "\n";
    return 0;
}