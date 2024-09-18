#include <iostream>
#include <limits>
#define MAX 50
using namespace std;

struct Month
{
    // const char *monthName;
    char *monthName;
    int days;
    struct Month *next;
};

struct Month *start = nullptr;

void createMonth(char *nm, int num)
{
    struct Month *month = (struct Month *)malloc(sizeof(struct Month));//allocating the memory location dynamically
    struct Month *iterator = start;
    month->monthName = nm;
    month->days = num;
    month->next = nullptr;
    if (start == nullptr)//if it is the first month
    {
        start = month;
        return;
    }
    while (iterator->next != nullptr)//to reach the last added month
    {
        iterator = iterator->next;
    }
    iterator->next = month;//connecting the new structure to the list 
    return;
}

void displayMonth()
{
    struct Month *iterator = start;
    while (iterator)
    {
        cout << " " << iterator->monthName << "   " << iterator->days << endl;
        iterator = iterator->next;
    }
}

int main()
{
    int days;
    // char *name;
    string name[12];//total 12 strings required to store 12 months' names
    for (int i = 0; i < 3; i++)
    {
        cout << "\nenter name of the " << (i + 1) << "th month: ";
        // cin.getline(name, MAX);
        getline(cin, name[i]);
        cout << "\nenter number of days in " << (i + 1) << "th month: ";
        cin >> days;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*ignore function ignores upto <1st parameter> number of characters in the input buffer or till it encounters a newline character, whichever comes first.
        In order to get the maximum number of characters that can be on the input buffer, so as to skip those number of characters, we use numeric_limits<streamsize>::max */

        /*This function is being used because from the second input onwards, the input for the name of the month is skipped, this happens because 31 followed by enter from the keyboard is basically '31\n', 31 goes into the variable but \n stays in the buffer and in the next iteration getline() receives it and stops the scan then again input for number of days is asked, essentially skipping the input for the name of the month*/
        createMonth(&(name[i])[0], days);//sending address of the first character of ith string
    }
   
    displayMonth();//calling the display function

    return 0;
}
