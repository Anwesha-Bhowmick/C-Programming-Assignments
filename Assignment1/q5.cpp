#include<iostream>
int main()
{
  long double n1, k, n2;
  long int round;
  std::cout<<"\nenter a real number: ";
  std::cin>>n1;
  std::cout<<"\nenter the place till which the number is to be rounded off (k) : ";
  std::cin>>k;
  round= (long int)((long double)(n1*k) + 0.5f);
  n2=(long double)round/k;
  std::cout << fixed;
  std::cout<<"\nthe rounded off number is : "<<n2<<"\n";
  return 0;
}