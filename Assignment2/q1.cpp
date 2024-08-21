#include<iostream>

int main()
{
  void function1(char *charPointer1, int &integerReference1);//declaring the function
  //void (*funcPointer1)(char *, int &);//declaring a function pointer to the "function1" type of functions
  //void function2(void (*funcPointer1)(char *, int &));//?
  //void (*funcPointer1)(char *, int &) function3();//?
  //void (*funcPointer1)(char *, int &) function4(void (*funcPointer1)(char *, int &));//?
  
  //OR
  
  typedef void (*newAlias)(char *, int &);//?
  void function2(newAlias);//?
  newAlias function3();//?
  newAlias function4(newAlias);//?
  return 0;
}
