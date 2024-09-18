#include <iostream>
int main()
{
    const char *str1 = "We love C++ programming\n";
    char str2[100];
    char *p = str2; /*name of an array is implicitly converted
     to pointer to the first element.*/
    std::cout << str1;

    while (*p++ = *str1++)
    {
    }
    // std::cout << str2;
}

/*The char pointer p points to the first element of str2. At line 7: the condition of the while loop is actually an assignment statement wherein the location pointed by 'p' i.e. the first element, is assigned the value of the first element of str1 i.e. 'W'. This continues till the last element of str1, following which it evaluates to false because *str1 becomes null and comes out of the loop. And str2 stores the required string character by character which is printed using cout */