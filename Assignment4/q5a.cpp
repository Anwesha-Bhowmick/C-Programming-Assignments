#include <iostream>

using namespace std;

void swapNums(int *p1, int *p2) // p1 points to a and p2 points to b
{
    int temp;
    temp = *p1; // using the dereference operator to get the value
    *p1 = *p2;
    *p2 = temp;
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
    swapNums(&a, &b); // sending the addresses of a and b as parameters to the function
    cout << "\nafter swapping : " << a << "  " << b;
    return 0;
}