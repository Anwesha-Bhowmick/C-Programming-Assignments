#include <iostream>
const char *createString()
{
    return "Practice makes a man perfect"; // returns the address of the first character
}
int *createInt()
{
    int x = 100;
    return &x; // returns the address of int x
}
int main()
{
    const char *str = createString(); // takes the address of the first character and then iterates until it reaches null sequence
    std::cout << "string = " << str << std::endl;
    int *ip = createInt(); // erroneous
    std::cout << "integer = " << *ip << std::endl;
}
/*Line 13 does not produce any error or warning because the type of string literals is by default "static", thus it will return a valid address because lifetime of a static variable is till the end of the program's run.*/
/*Line 15 is erroneous because lifetime of the variable "x" is upto the createInt() function only. When in line 15 we try to access the address of "x", it is already gone i.e., it does not exist and hence its address cannot be returned*/