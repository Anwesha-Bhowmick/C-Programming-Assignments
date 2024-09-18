#include <iostream>
#include <limits>
#define MAX 50
using namespace std;
int main()
{
    char monthName[12][MAX];
    int monthDays[12];
    for (int i = 0; i < 12; i++)
    {
        cout << "\nenter name of the " << (i + 1) << "th month: ";
        cin.getline(monthName[i], MAX);
        // getline(cin, monthName[i]);
        cout << "\nenter number of days in " << (i + 1) << "th month: ";
        cin >> monthDays[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < 12; i++)
    {
        cout << " " << monthName[i] << "  " << monthDays[i] << endl;
    }

    return 0;
}