#include <iostream>
#include <limits>
#define MAX 50
using namespace std;
int main()
{
    char monthName[12][MAX];//there are 12 months in a year,so number of rows is 12, and the max length of each month name is assumed to be of 50 characters, thus the column size
    int monthDays[12];//12 entries for 12 months
    for (int i = 0; i < 12; i++)
    {
        cout << "\nenter name of the " << (i + 1) << "th month: ";
        cin.getline(monthName[i], MAX);
        // getline(cin, monthName[i]);
        cout << "\nenter number of days in " << (i + 1) << "th month: ";
        cin >> monthDays[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*ignore function ignores upto <1st parameter> number of characters in the input buffer or till it encounters a newline character, whichever comes first.
        In order to get the maximum number of characters that can be on the input buffer, so as to skip those number of characters, we use numeric_limits<streamsize>::max */

        /*This function is being used because from the second input onwards, the input for the name of the month is skipped, this happens because 31 followed by enter from the keyboard is basically '31\n', 31 goes into the variable but \n stays in the buffer and in the next iteration getline() receives it and stops the scan then again input for number of days is asked, essentially skipping the input for the name of the month*/
    }

    for (int i = 0; i < 12; i++)
    {
        cout << " " << monthName[i] << "  " << monthDays[i] << endl;
    }

    return 0;
}
