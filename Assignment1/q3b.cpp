#include <iostream>

int main()
{
    float x, y;
    std::cout << "\nenter the value of y: ";
    std::cin >> y;
    x = y - 20 * 6 / 9;
    std::cout << "\nvalue of x before modification: " << x << "\n";
    x = y - 20 * 6 / 9.0;
    std::cout << "\nvalue of x after modification: " << x << "\n";
    return 0;
}