#include <iostream>

using namespace std;
int main()
{
    char *str = "India vs Pakistan, Asia Cup 2023";
    str[7] = 'V'; // this generates an error as strings are immutable
    double darr[] = {2.3, 4.5, 5.5};
    *(darr + 3) = 6.5;
    extern float f; // generates error as no other file is being included wherein the definition of "f" can be found
    float g = f * 100.5;
    short int i = 89;
    void *v = &i;
    int *ip = static_cast<int *>(v); // returns garbage value as "i" is of type "short int" and here in static_cast we are writing "int"
    cout << "integer = " << *ip;
}
