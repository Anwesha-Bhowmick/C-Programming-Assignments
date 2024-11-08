#include <iostream>

using namespace std;

struct X
{
    int i;
    X(int val) // constructor
    {
        this->i = val;
    }
    X operator+(int val) // for X + int
    {
        return X(this->i + val);
    }
    X operator+(X &x1) // for X + X
    {
        return X(this->i + x1.i);
    }
};
struct Y
{
    int i;
    Y(int val) // constructor
    {
        this->i = val;
    }
    Y(X x) //* for X to Y
    {
        this->i = x.i;
    }
    Y operator+(int val) // for Y + int
    {
        return Y(this->i + val);
    }
    Y operator+(X x) // for Y + X
    {
        return Y(this->i + x.i);
    }
    Y operator+(Y &y1) // for Y + Y
    {
        return Y(this->i + y1.i);
    }
    operator int() // conversion of operator to int
    {
        return this->i;
    }
};
extern X operator*(X x, Y y);
extern int f(X x);
X operator*(X x, Y y)
{
    return X(x.i * y.i);
}
// X operator*(int x, Y y)
// {
//     return X(x * y.i);
// }

int f(X x)
{
    return x.i;
}

X x = 1;
Y y = x;
int i = 2;
int main()
{
    // i + 10;
    // y + 10;
    // y + 10 * y;
    // x + y + i;
    // x *x + i;
    // f(7);
    // f(y);
    // y + y;
    // 106 + y;
    cout << (i + 10) << endl;            // int + int so no conversion
    cout << (y + 10).i << endl;          // 10 i.e. int is converted into Y then added
    cout << (y + (X(10) * y)).i << endl; // if we did 10 * y it would give ambiguous overload between the default operator * for int *int and the overloaded one between X and Y. So, we converted 10 into X explicitly to resolve it
    cout << ((x + y) + i).i << endl;     // y is converted into X and then added with x then i is converted into X then added with the result of the previous operation
    cout << (x * x).i << endl;           // the operation * is overloaded so first x is converted into Y then the overloaded operator multiplies them
    cout << f(7) << endl;                // 7 is converted from int to X then the function is called as the function takes X as argument
    cout << f(int(y)) << endl;           // we cannot do f(y) because the argument of the function f is X so y will have to be converted into X but there is no such constructor.So, y  is converted into integer explicitly then passed
    cout << (y + y).i << endl;           // Y + Y is performed using the overloaded + operator
    cout << (106 + y) << endl;           // y is converted into int and then added
}
