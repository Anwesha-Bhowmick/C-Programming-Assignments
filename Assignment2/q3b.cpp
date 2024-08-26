#include<iostream>
using namespace std;

void f1()
{
  static int count=0;//using a local static variable 
  count++;
  cout<<"I have been called "<<count<<" times\n";
  return;
}

int main()
{
  int n,i;
  
  cout<<"\nenter the number of times you want to call the function: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    f1();
  }
  return 0;
}
