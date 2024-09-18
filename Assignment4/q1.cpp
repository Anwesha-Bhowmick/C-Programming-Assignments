#include "q1.h"
#include <iostream>

// initialisations
char character1;
char *pointer1 = &character1;                  // a pointer to a character
int array1[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // an array of 10 integers
int (&reference1)[10] = array1;                // a reference to an array of 10 integers
char array2[5]{'a', 'b', 'c', 'd', 'e'};
char (*pointer2)[5] = &array2; // a pointer to an array of character strings
char **pointer3 = &pointer1;
const int integer1 = 10;                    // a constant integer
const int *pointer4 = &integer1;            // a pointer to a constant integer
int integer2 = 20;                          // an integer
int *const pointer5 = &integer2;            // a constant pointer to an integer
const double doublenum1 = 10.10;            // a constant double
const double *const pointer6 = &doublenum1; // a constant pointer to a constant double

int main()
{
    return 0;
}