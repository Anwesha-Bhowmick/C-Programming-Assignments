#include<iostream>

int main()
{ 
  float x, expression;
  std::cout<<"\nenter a real number : ";
  std::cin>>x;
  expression=(((x+1/x)+1/(x+1/x)) + 1/((x+1/x)+1/(x+1/x)));
  std::cout<<"\n the numerical value of the expression is : "<<expression<<"\n";
  return 0;
}


