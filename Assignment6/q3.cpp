#include <iostream>
using namespace std;

struct X
{
    X() { cout << "default constructor\n"; };
    X(X &&x) { cout << "move constructor\n"; };
    X(const X &x) { cout << "copy constructor\n"; };
    X &operator=(const X &)
    {
        cout << "copy assignment\n";
        return *this;
    };
    ~X() { cout << "Destructor\n"; };
};

X foo(X x)
{
    return x;
}
int main()
{
    X obj;
    obj = foo(obj);
}

/*at line 23, object of X type is created thus the default constructor X() is called which will print "default constructor". at line 24 "foo" function is called with the object obj. so at line 17 it is passed as value into the argument thus copy contructor is called which prints "copy constructor". inside foo, it returns x which is a copy of obj thus it calls the move constructor which prints "move constructor". when the assignment is done in line24, copy assignment operator is called which prints "copy assignment". when the main function ends, destructors are called for all ths objects created.once for the copy of obj in foo(obj) in the argument, once for the temporary object being returned from foo after the move constructor, and finally for obj*/