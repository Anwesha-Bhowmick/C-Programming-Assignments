#include<iostream>
using namespace std;
struct X{
int i;
X(int);
X operator+(int);//X  + 
};
struct Y{
int i;
Y operator+(X);//Y+X
operator int();//converting Y into int
};
extern X operator*(X, Y);
extern int f(X);
X x = 1;
Y y = x;
int i = 2;
int main() 
{
  i + 10;//no explicit conversion as both are integers
  y + 10;//10 in converted into X using X(10) and the Y+X is done using operator+(X)
  y + 10 * y;//in 10*y, Y is converted into int using operator int(). the result is then converted to X when adding y+ X(10*y) and then finally Y+X is done using operator+(X)
  x + y + i;//first y is converted to int using operator int() then x+int is to be done so operator+(int) and finally the result is added to i which is int
  x * x + i;//x*x calls operator(X,Y) which returns an X then for adding with int i, X is converted into int
  f(7);//no conversion
  f(y);//Y is converted into int using operator int() before passing to f
  y + y;//operator+(X) is called with the argument X(y.1) where first y is converted into an integer then passed into X(int)
  106 + y;// Y is converted into int using operator int() then added to 106 
}
