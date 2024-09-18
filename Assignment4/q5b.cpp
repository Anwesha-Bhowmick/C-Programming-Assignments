#include <iostream>

using namespace std;

void swapNums(int &r1, int &r2) // r1, r2 are basically aliases of a,b respectively
{
    int temp;
    temp = r1;
    r1 = r2;
    r2 = temp;
    return;
}

int main()
{
    int a, b;
    cout << "\nenter the first number: ";
    cin >> a;
    cout << "\nenter the second number: ";
    cin >> b;
    cout << "\nbefore swapping : " << a << "  " << b;
    swapNums(a, b); // sending a and b to initialise the integer references in the function definition
    cout << "\nafter swapping : " << a << "  " << b;
    return 0;
}