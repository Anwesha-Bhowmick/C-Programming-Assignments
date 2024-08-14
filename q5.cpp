#include<iostream>

int main()
{
  double n1, k, n2;
  int round;
  std::cout<<"\nenter a real number: ";
  std::cin>>n1;
  std::cout<<"\nenter the place till which the number is to be rounded off (k) : ";
  std::cin>>k;
  round=int((n1*k) + 0.5);
  n2=double(round/k);
  std::cout<<"\nthe rounded off number is : "<<n2<<"\n";

}
