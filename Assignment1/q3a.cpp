#include<iostream>

int main()
{
  char vowels1, vowels2, vowels3, vowels4, vowels5;
  char a1[]={'a','e','i','o','u'};
  char capVowels1, capVowels2, capVowels3, capVowels4, capVowels5;
  char a2[]={'A','E','I','O','U'};
  vowels1=a1[0];
  vowels2=a1[1];
  vowels3=a1[2];
  vowels4=a1[3];
  vowels5=a1[4];
  capVowels1=a2[0];
  capVowels2=a2[1];
  capVowels3=a2[2];
  capVowels4=a2[3];
  capVowels5=a2[4];
  std::cout<<"\nvowels2-vowels1 = "<<vowels2-vowels1;
  std::cout<<"\ncapVowels2-capVowels1 = "<<capVowels2-capVowels1<<"\n";
}
