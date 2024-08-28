#include <iostream>
#include <cstring>

// selection sorting algorithm for integers
void sort1(int *a, int n)
{
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
}

// function to compare two strings
int stringCompare(char *str1, char *str2)
{
    int n = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);//taking the smaller string's size for char by char comparison
    for (unsigned int i = 0; i < n; i++)
    {
        if (str1[i] > str2[i])//conmparing the strings, character by character
        {
            return 1;//swap
        }
        if (str1[i] < str2[i])
        {
            return 0;//no swap
        }
    }
    if (strlen(str1) > strlen(str2))//this case is need when both strings have identical upto a certain point but one of the strings exceeds in size such as : "robust" and "robust code", both have "robust" substring in them 
    {
        return 1;//swapped
    }
    else
    {
        return 0;//no swap
    }
}

// selection sorting algorithm for strings
void sort2(char *a[], int n)
{
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = i + 1; j < n; j++)
            if (stringCompare(a[i], a[j]))//calling the user-defined function
                std::swap(a[i], a[j]);
}

int main()
{
    int a[]{-2, 3, 8, 10, 7, 56, 90};
    char *str[]{"hello", "world", "iacs", "raining"}; // if we don't add 'const' keyword then we get the error: ISO C++ forbids converting a string constant to 'char*', this happens because string constants are of type 'const char[]' and thus it cannot be assigned to a pointer to non const character.
    // * is mandatory, otherwise it will tell the compiler that it is an array of characters and not an array of strings
    void (*sortInt)(int *, int);
    sortInt = &sort1;
    sortInt(a, 7); // call via function pointer
    for (unsigned int i = 0; i < 7; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    void (*sortString)(char *[], int);
    sortString = &sort2;
    sortString(str, 4);//call via function pointer
    for (unsigned int i = 0; i < 4; i++)
        std::cout << str[i] << " ";
    std::cout << "\n";
    return 0;
}
