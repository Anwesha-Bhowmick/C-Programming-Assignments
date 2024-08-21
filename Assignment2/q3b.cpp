#include<iostream>
using namespace std;

void f1(int count)
{
  count++;
  cout<<"\nI have been called "<<count<<" times\n";
  return;
}

int main()
{
  int n,i;
  static int count=0;
  cout<<"\nenter the number of times you want to call the function: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    f1(count);
  }
  return 0;
}
