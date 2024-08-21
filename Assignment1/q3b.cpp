#include <iostream>

int main()
{
    float x, y;
    std::cout << "\nenter the value of y: ";
    std::cin >> y;
    x = y - 20 * 6 / 9; /*this happens because the division implicitly casts the result into integer and the final result is returned as an integer.*/
    std::cout << "\nvalue of x before modification: " << x << "\n";
    x = y - 20 * 6 / 9.0;/*the value 9.0 changes the return type of the division operation to float and as a result the final value is returned as a float and not implicitly casted as an integer.*/
    std::cout << "\nvalue of x after modification: " << x << "\n";
    return 0;
}