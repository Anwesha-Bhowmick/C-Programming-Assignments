#include<iostream>
using namespace std;
int count=0;

void f1()
{
  count++;
  cout<<"\nI have been called "<<count<<" times\n";
  return;
}

void callFunc(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    f1();
  }  
}

int main()
{
  int n;
  cout<<"\nenter the number of times you want to call the function: ";
  cin>>n;
  callFunc(n);
  return 0;
}
