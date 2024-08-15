#include<iostream>
int main()
{
int n,days, weeks, years;
std::cout<<"\nenter the number of days : ";
std::cin>>n;
std::cout<<"\nn = "<<n;
years=n/365;
weeks=(n%365)/7;
days=(n%365)%7;
std::cout<<"\n"<<years<<" years "<<weeks<<" weeks "<<days<<" days\n"; 
return 0;
}

