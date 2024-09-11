#include<iostream>

int main()
{
  //declarations
  extern char *pointer1;//a pointer to a character
  extern int array1[10];//an array of 10 integers
  extern int (&reference1)[10];//a reference to an array of 10 integers  ??
  extern char (*pointer2)[];//a pointer to an array of character strings  ??
  extern char **pointer3;//a pointer to a pointer to a character
  extern const int integer1;//a constant integer
  extern const int *pointer4;//a pointer to a constant integer
  extern int * const pointer5;//a constant pointer to an integer ??
  extern const double * const pointer6;//a constant pointer to a constant double ?? 
  
  //initialisations
  char character1;
  pointer1=&character1;//a pointer to a character
  array1[] {1,2,3,4,5,6,7,8,9,10};//an array of 10 integers
  &reference1=array1;//a reference to an array of 10 integers  ??
  char array2[] {'a','b','c','d','e'};
  pointer2=&array2;//a pointer to an array of character strings  ??
  integer1=10;//a constant integer
  pointer4=&integer1;//a pointer to a constant integer
  int integer2=20;//an integer
  pointer5=&integer2;//a constant pointer to an integer ??
  const double doublenum1=10.10;//a constant double
  pointer6=&doublenum1;//a constant pointer to a constant double ?? 
  
  
  
  
  
  
}
