#include <iostream>

void function1(char *charPointer1, int &integerReference1); // declaring the function

typedef void (*newAlias)(char *, int &); // alias

newAlias funcPointer1; // declaring a function pointer to the "function1"

void function2(newAlias); // declaring a function that takes such a pointer as a parameter

newAlias function3(); // declaring a function returning such a pointer

newAlias function4(newAlias) // defining a function which takes such pointer as parameter and return such pointer
{
    return funcPointer1;
}

int main()
{
    return 0;
}
