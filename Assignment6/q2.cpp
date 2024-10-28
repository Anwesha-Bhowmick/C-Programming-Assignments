#include <iostream>
using namespace std;

struct foo
{
    foo() { cout << "foo()\n"; }
    ~foo() { cout << "~foo()\n"; }
    int i{5};
};
struct obj
{
    const foo &getFoo() { return my_foo; };
    foo my_foo;
};
int main()
{
    obj *o = new obj();                     // 1
    const foo &val = o->getFoo();           // 2
    cout << "val.i=" << val.i << std::endl; // 3
    delete o;                               // 4
    cout << "val.i=" << val.i << std::endl; // 5
}

/* 1 creates a new object of type obj pointed by "o". This leads to the calling of the default constructor of obj which declares a foo object, so the user defined constructor of foo which prints "foo()" and initialises i to "5". When line 2 is executed the function getFoo my_foo is returned whose alias is val (since we are using reference). when line 2 is executed then the destructor of foo is called thus the memory location is released and "~foo()" is printed. When line 5 tries to execute it is accessing a memory that has already been deallocated in line 4, thus garbage value is returned.
 */