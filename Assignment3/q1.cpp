#include <iostream>
#include <ctype.h>
#include <string.h>
#include "revwords.h"
#define MAX 100
using namespace std;

int main()
{
    // char str[] = "University of Cambridge!";
    char str[MAX];
    cout << "\nenter the string: ";
    cin.getline(str, MAX);
    cout << "The original string is : " << str;
    reverse_words(str);
    cout << "\nThe modified string is : " << str << "\n";
    return 0;
}