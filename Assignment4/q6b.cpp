#include <iostream>
#define MAX 50
using namespace std;

struct Month
{
    const char *monthName;
    int monthDays;
};

int main()
{
    Month year[12] = {
        {"January", 31},
        {"February", 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31},
    };//array of structures

    for (int i = 0; i < 12; i++)
    {
        cout << "     " << year[i].monthName << "     " << year[i].monthDays << endl;
    }

    return 0;
}
