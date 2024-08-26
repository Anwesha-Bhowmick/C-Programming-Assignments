#include<iostream>
using namespace std;
int count=0;//using a global variable

void f1()
{
  count++;
  cout<<"I have been called "<<count<<" times\n";
  return;
}

int main()
{
  int i,n;
  cout<<"\nenter the number of times you want to call the function: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    f1();
  }
  return 0;
}
