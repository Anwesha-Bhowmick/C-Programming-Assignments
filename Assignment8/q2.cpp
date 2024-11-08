#include <iostream>
using namespace std;

class Base
{
public:
    virtual void iam() // it is declared as a virtual function because the type of pointer in the print function's argument is of type Base so it can point to both Base as well as Derived but we want that if it points to Derived then it should call Derived class' iam().
    {
        cout << "Base\n";
    }
};

class D1 : public Base
{
    void iam()
    {
        cout << "D1\n";
    }
};

class D2 : public Base
{
    void iam()
    {
        cout << "D2\n";
    }
};

void print(Base *bptr)
{ /* implement this function */
    bptr->iam();
}
int main()
{
    Base b;
    D1 d1;
    D2 d2;
    print(&b);
    print(&d1);
    print(&d2);
}