#include <iostream>
#include <vector>
#include <list>
using namespace std;
class base
{
    int x;
    vector<double> v;

public:
    base(int y, vector<double> z) : x{y}, v{z} {}
    void basePrint() // for printing the members of the base class
    {
        cout << "x = " << x << endl;
        cout << "v = ";
        for (double v1 : v)
        {
            cout << v1 << " ";
        }
        cout << endl;
    }
};
class derived : public base
{
    list<bool> l;

public:
    derived(int y, vector<double> z) : base{y, z} // initializes x and v in base class
    {
        l = list<bool>(); // empty list
    }
    derived(int y, vector<double> z, list<bool> el) : base{y, z} // initializes x and v in base class
    {
        l = list<bool>(el); // l is initialised to the parameterised list el
    }
    void print()
    {
        basePrint();              // calling the function to print inherited components
        cout << "The list is : "; // printing the "special" component
        for (bool x : l)
        {
            cout << x << "  ";
        }
        cout << endl;
    }
};
int main()
{
    derived d{10, {1.5, 2.5, 3.5}, {true, false}};
    d.print();
}
